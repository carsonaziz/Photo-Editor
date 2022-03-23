#pragma once

#include "photoengine/events/window_event.h"
#include "photoengine/window.h"

namespace PhotoEngine
{
    class Application
    {
    private:
        bool m_running;

        std::unique_ptr<Window> m_window;

    public:
        Application();
        virtual ~Application();

        virtual void on_event(Event& e);

        bool on_window_close(WindowCloseEvent& event);

        void run();
    };

    Application* create();
}