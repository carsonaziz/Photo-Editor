#pragma once

#include "photoengine/gui_interface.h"

class GUIEditor : public PhotoEngine::GUIInterface
{
public:
    bool m_show_adjustment_panel;
    bool m_show_layer_panel;
    bool m_show_color_panel;
    bool m_show_tool_panel;

private:
    void dockspace();
    void viewport();
    void footer();
    void adjustment(bool* p_open);
    void layer(bool* p_open);
    void color(bool* p_open);
    void tool(bool* p_open);

    void show_layers();
public:
    GUIEditor()
        : m_show_adjustment_panel(true), m_show_layer_panel(true), m_show_color_panel(true), m_show_tool_panel(true) {}
    ~GUIEditor() {}

    virtual void render() override;
};