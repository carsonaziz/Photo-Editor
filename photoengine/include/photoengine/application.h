#pragma once

#include "photoengine/events/window_event.h"
#include "photoengine/window.h"
#include "photoengine/layers/layer_list.h"
#include "photoengine/gui_interface.h"

namespace PhotoEngine
{
    class Application
    {
    protected:
        bool m_running;

        std::shared_ptr<Window> m_window;

        std::unique_ptr<GUIInterface> m_gui_interface;
        std::shared_ptr<Image> m_viewport;
        std::shared_ptr<LayerList> m_layer_list;
    public:
        static Application* s_instance;

    public:
        Application();
        virtual ~Application();

        virtual void on_event(Event& e);
        bool on_window_close(WindowCloseEvent& event);

        inline std::shared_ptr<Window> get_window() { return m_window; }
        inline std::shared_ptr<LayerList> get_layer_list() { return m_layer_list; }
        inline std::shared_ptr<Image> get_viewport() { return m_viewport; }

        static Application* get() {return s_instance; }

        void run();
    };

    Application* create();
}