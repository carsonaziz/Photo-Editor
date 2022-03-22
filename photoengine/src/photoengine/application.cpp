#include "photoengine/application.h"

#include "photoengine/log.h"

#include "photoengine/events/keyboard_event.h"

namespace PhotoEngine
{
    Application::Application()
    {

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
        WindowCloseEvent event;
        on_event(event);
    }
}