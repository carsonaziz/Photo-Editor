#pragma once

#include "photoengine/events/window_event.h"
#include "photoengine/window.h"
#include "photoengine/layers/layer_list.h"

namespace PhotoEngine
{
    class Application
    {
    private:
        bool m_running;

        std::shared_ptr<Window> m_window;
        std::unique_ptr<LayerList> m_layer_list;
    public:
        static Application* s_instance;

    public:
        Application();
        virtual ~Application();

        virtual void on_event(Event& e);
        bool on_window_close(WindowCloseEvent& event);

        inline std::shared_ptr<Window> get_window() { return m_window; }
        static Application* get() {return s_instance; }

        void run();
    };

    Application* create();
}