#pragma once

#include "layer.h"

namespace PhotoEngine
{
    class ImGUILayer : public Layer
    {
    private:
        bool mouse_button_pressed(Event& event);

        static void dockspace();
        static void viewport();
        static void layer_panel(bool* p_open);
        static void adjustment_panel(bool* p_open);
        static void color_panel(bool* p_open);
        static void tool_panel(bool* p_open);

        static void style_colors_dark();
    public:
        ImGUILayer() {}
        ~ImGUILayer() {}

        virtual void on_attach() override;
        virtual void on_detach() override;

        virtual void on_event(Event& event) override;
        virtual void update() override;
        virtual void render() const override;
    };
}