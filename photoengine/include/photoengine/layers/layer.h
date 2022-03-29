#pragma once

#include "photoengine/events/event.h"
#include "photoengine/events/mouse_event.h"
#include "photoengine/image.h"

#include <string>

namespace PhotoEngine
{
    class Layer
    {
    private:
        Image* m_image;
        int m_width, m_height;
        std::string m_name;

        bool m_visible;
        bool m_selected;

    public:
        Layer(int width, int height, std::string name);
        Layer(int width, int height, std::string name, int r, int g, int b);
        ~Layer();

        void on_attach();
        void on_detach();

        void on_event(Event& event);
        bool mouse_moved(MouseMovedEvent& event);

        void update();
        void render();

        inline const std::string& get_name() { return m_name; }
        inline Image* get_image() { return m_image; }
        inline bool is_visible() { return m_visible; }
        inline bool is_selected() { return m_selected; }

        inline void set_selected(bool selected) { m_selected = selected; }
        inline void set_visible(bool visible) { m_visible = visible; }
        inline void toggle_visibility() { m_visible = m_visible ? false : true; }
    };
}