#include "photoengine/application.h"

#include "photoengine/log.h"
#include "photoengine/events/keyboard_event.h"
#include "photoengine/gui_interface.h"

// TEMP
#include <glfw/glfw3.h>
#include <glad/glad.h>

namespace PhotoEngine
{
    Application* Application::s_instance = nullptr;

    Application::Application() : m_running(true)
    {
        s_instance = this;
        m_window = std::make_shared<Window>();
        m_window->set_event_callback(std::bind(&Application::on_event, this, std::placeholders::_1));

        m_layer_list = std::make_shared<LayerList>();
        m_viewport = std::make_shared<Image>(500, 500);

        m_gui_interface = nullptr;
    }

    Application::~Application()
    {
        for (Layer* layer : *m_layer_list)
        {
            layer->on_detach();
            delete layer;
        }
    }

    void Application::on_event(Event& event)
    {
        EventHandler handler(event);
        handler.handle_event<WindowCloseEvent>(std::bind(&Application::on_window_close, this, std::placeholders::_1));
        // PE_ENGINE_TRACE("{}", event.to_string());

        for (auto it = m_layer_list->end(); it != m_layer_list->begin(); it--)
        {
            if (event.m_handled) break;
            (*it)->on_event(event);
        }
    }

    bool Application::on_window_close(WindowCloseEvent& event)
    {
        m_running = false;

        return true;
    }

    void Application::run()
    {
        while (m_running)
        {
            for (Layer* layer : *m_layer_list)
            {
                layer->update();
                layer->render();
            }

            m_viewport->generate_texture();

            glClearColor(0.2f, 0.3f, 0.8f, 1.0);
            glClear(GL_COLOR_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

            m_gui_interface->begin();
            m_gui_interface->render();
            m_gui_interface->end();

            m_window->update();
        }
    }
}