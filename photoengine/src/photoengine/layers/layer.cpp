#include "photoengine/layers/layer.h"

#include "photoengine/application.h"
#include "photoengine/log.h"

#include <glad/glad.h>

namespace PhotoEngine
{
    Layer::Layer(int width, int height, std::string name) : m_width(width), m_height(height), m_name(name), m_visible(true), m_selected(false)
    {
        m_image = new Image(m_width, m_height);
    }

    Layer::Layer(int width, int height, std::string name, int r, int g, int b) : m_width(width), m_height(height), m_name(name), m_visible(true), m_selected(false)
    {
        m_image = new Image(m_width, m_height, r, g, b);
    }

    Layer::~Layer()
    {
        delete m_image;
    }

    void Layer::on_attach()
    {

    }

    void Layer::on_detach()
    {

    }

    void Layer::on_event(Event& event)
    {
        EventHandler handler(event);
        handler.handle_event<MouseMovedEvent>(std::bind(&Layer::mouse_moved, this, std::placeholders::_1));
    }

    bool Layer::mouse_moved(MouseMovedEvent& event)
    {
        // PE_ENGINE_TRACE("{}", event.to_string());

        return true;
    }

    void Layer::update()
    {
        m_image->generate_texture();
    }

    void Layer::render()
    {
        auto viewport = Application::get()->get_viewport();
        if (m_visible)
        {
            for (int i = 0; i < viewport->Width * viewport->Height; i++)
            {
                // Temp "transparency"
                if (m_image->Data[i * 4 + 3] == 255)
                {
                    viewport->Data[i * 4 + 0] = m_image->Data[i * 4 + 0];
                    viewport->Data[i * 4 + 1] = m_image->Data[i * 4 + 1];
                    viewport->Data[i * 4 + 2] = m_image->Data[i * 4 + 2];
                    viewport->Data[i * 4 + 3] = m_image->Data[i * 4 + 3];
                }
            }
        }
    }
}