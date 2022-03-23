#include "photoengine/application.h"

#include "photoengine/log.h"

#include "photoengine/events/keyboard_event.h"

namespace PhotoEngine
{
    Application::Application() : m_running(true)
    {
        m_window = std::make_unique<Window>();
        m_window->set_event_callback(std::bind(&Application::on_event, this, std::placeholders::_1));
    }

    Application::~Application()
    {

    }

    void Application::on_event(Event& event)
    {
        EventHandler handler(event);
        handler.handle_event<WindowCloseEvent>(std::bind(&Application::on_window_close, this, std::placeholders::_1));
        PE_ENGINE_TRACE("{}", event.to_string());
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
            m_window->update();
        }
    }
}