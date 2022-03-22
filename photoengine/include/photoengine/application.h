#pragma once

#include "photoengine/events/window_event.h"

namespace PhotoEngine
{
    class Application
    {
    private:
        bool m_running;

    public:
        Application();
        virtual ~Application();

        void on_event(Event& e);
        bool on_window_close(WindowCloseEvent& event);

        void run();
    };

    Application* create();
}