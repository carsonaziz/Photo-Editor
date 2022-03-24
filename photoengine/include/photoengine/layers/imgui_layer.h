#pragma once

#include "layer.h"
#include "photoengine/gui/gui_item.h"

namespace PhotoEngine
{
    class ImGUILayer : public Layer
    {
    private:
        std::unique_ptr<GUIAdjustment> m_gui_adjustment;
        std::unique_ptr<GUILayer> m_gui_layer;
        std::unique_ptr<GUIColor> m_gui_color;
        std::unique_ptr<GUITool> m_gui_tool;
        std::unique_ptr<GUIFooter> m_gui_footer;
        std::unique_ptr<GUIViewport> m_gui_viewport;

    private:
        bool mouse_button_pressed(Event& event);

        static void dockspace();
        static void viewport();

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