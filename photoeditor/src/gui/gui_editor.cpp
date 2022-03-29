#include "gui/gui_editor.h"

#include "imgui.h"
#include "photoengine/application.h"
#include "photoengine/log.h"
#include "photoengine/layers/layer.h"

#include <string>

// TEMP
#include <glad/glad.h>

void GUIEditor::render()
{
    dockspace();
    viewport();
    footer();
    adjustment(&m_show_adjustment_panel);
    layer(&m_show_layer_panel);
    color(&m_show_color_panel);
    tool(&m_show_tool_panel);
}

void GUIEditor::dockspace()
{
    bool p_open = true;

    static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

    // We are using the ImGuiWindowFlags_NoDocking flag to make the parent window not dockable into,
    // because it would be confusing to have two docking targets within each others.
    ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;

    const ImGuiViewport* viewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(viewport->WorkPos);
    ImGui::SetNextWindowSize(viewport->WorkSize);
    ImGui::SetNextWindowViewport(viewport->ID);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
    window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
    window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;

    // When using ImGuiDockNodeFlags_PassthruCentralNode, DockSpace() will render our background
    // and handle the pass-thru hole, so we ask Begin() to not render a background.
    if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
        window_flags |= ImGuiWindowFlags_NoBackground;

    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));

    ImGui::Begin("Dockspace", &p_open, window_flags);
    ImGui::PopStyleVar();
    ImGui::PopStyleVar(2);
    ImGuiIO& io = ImGui::GetIO();
    if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
    {
        ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
        ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
    }


    // Menu Bar
    if (ImGui::BeginMenuBar())
    {
        if (ImGui::BeginMenu("File"))
        {
            ImGui::MenuItem("Open");
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Edit"))
        {
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Filter"))
        {
            ImGui::MenuItem("Gaussian Blur", NULL);
            ImGui::MenuItem("Negative", NULL);
            ImGui::MenuItem("Greyscale", NULL);
            ImGui::MenuItem("Sepia", NULL);
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Window"))
        {
            ImGui::MenuItem("Adjustments", NULL, &m_show_adjustment_panel);
            ImGui::MenuItem("Layers", NULL, &m_show_layer_panel);
            ImGui::MenuItem("Color", NULL, &m_show_color_panel);
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Options"))
        {
            // Disabling fullscreen would allow the window to be moved to the front of other windows,
            // which we can't undo at the moment without finer window depth/z control.
            ImGui::MenuItem("Fullscreen");
            ImGui::MenuItem("Padding");
            ImGui::Separator();

            if (ImGui::MenuItem("Flag: NoSplit",                "", (dockspace_flags & ImGuiDockNodeFlags_NoSplit) != 0))                 { dockspace_flags ^= ImGuiDockNodeFlags_NoSplit; }
            if (ImGui::MenuItem("Flag: NoResize",               "", (dockspace_flags & ImGuiDockNodeFlags_NoResize) != 0))                { dockspace_flags ^= ImGuiDockNodeFlags_NoResize; }
            if (ImGui::MenuItem("Flag: NoDockingInCentralNode", "", (dockspace_flags & ImGuiDockNodeFlags_NoDockingInCentralNode) != 0))  { dockspace_flags ^= ImGuiDockNodeFlags_NoDockingInCentralNode; }
            if (ImGui::MenuItem("Flag: AutoHideTabBar",         "", (dockspace_flags & ImGuiDockNodeFlags_AutoHideTabBar) != 0))          { dockspace_flags ^= ImGuiDockNodeFlags_AutoHideTabBar; }
            ImGui::Separator();

            ImGui::MenuItem("Close");
            ImGui::EndMenu();
        }

        std::string desc = "Test description";
        ImGui::TextDisabled("(?)");
        if (ImGui::IsItemHovered())
        {
            ImGui::BeginTooltip();
            ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
            ImGui::TextUnformatted(desc.c_str());
            ImGui::PopTextWrapPos();
            ImGui::EndTooltip();
        }
        

        ImGui::EndMenuBar();
    }

    ImGui::End();
}

void GUIEditor::viewport()
{
    bool p_open = true;
    ImGuiWindowFlags window_flags = 0;
    window_flags |= ImGuiWindowFlags_HorizontalScrollbar;
    ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.12f, 0.12f, 0.12f, 1.00f));
    ImGui::Begin("Viewport", &p_open, window_flags);
    float xsize = 700, ysize = 700;
    // ImVec2 image_zoom_size = ImVec2(xsize * ((float)m_zoom/100.0f), ysize * ((float)m_zoom/100.0f));
    ImVec2 image_zoom_size = ImVec2(xsize, ysize);
    ImGui::SetCursorPos(ImVec2((ImGui::GetWindowSize().x - image_zoom_size.x)*0.5f, (ImGui::GetWindowSize().y - image_zoom_size.y)*0.5f));
    ImGui::Image((ImTextureID)PhotoEngine::Application::get()->get_viewport()->texture_id, image_zoom_size, ImVec2(1, 0), ImVec2(0, 1));
    // ImGui::Image(nullptr, image_zoom_size, ImVec2(1, 0), ImVec2(0, 1));
    ImGui::PopStyleColor();
    ImGui::End();
}

void GUIEditor::adjustment(bool* p_open)
{
    ImGuiWindowFlags window_flags = 0;

    if (*p_open)
    {
        if (ImGui::Begin("Adjustments", p_open, window_flags))
        {

        }
        ImGui::End();
    }
}

void GUIEditor::layer(bool* p_open)
{
    ImGuiWindowFlags window_flags = 0;

    int opacity = 100;

    if (*p_open)
    {
        if (ImGui::Begin("Layers", p_open, window_flags))
        {
            ImGui::PushItemWidth(50.0f);
            ImGui::DragInt("Opacity", &opacity, 1, 0, 100, "%i%%");
            // float strength = (float)m_image.opacity/100.0f * 255.0f;
            // for (int i = 0; i < m_image.width * m_image.height; i++)
            // {
            //     m_image.data[i * 4 + 3] = strength;
            // }

            ImGui::Separator();

            show_layers();
        }
        ImGui::End();
    }
}

void GUIEditor::color(bool* p_open)
{
    float col[3] = { 0.5f, 0.5f, 0.5f };

    ImGuiWindowFlags window_flags = 0;

    if (*p_open)
    {
        if (ImGui::Begin("Color", p_open, window_flags))
        {
            // ImGui::ColorEdit4("##color", (float*)&style.Colors[i], ImGuiColorEditFlags_AlphaBar | alpha_flags);
            ImGui::ColorEdit3("##color", col);
        }
        ImGui::End();
    }
}

void GUIEditor::tool(bool* p_open)
{
    ImGuiWindowClass window_class;
    window_class.DockNodeFlagsOverrideSet = ImGuiDockNodeFlags_AutoHideTabBar;
    window_class.DockNodeFlagsOverrideSet = ImGuiDockNodeFlags_NoResize;
    ImGui::SetNextWindowClass(&window_class);
    ImGuiWindowFlags window_flags = 0;
            
    if (!ImGui::Begin("Tools", p_open, window_flags))
    {
        ImGui::End();
    } else
    {
        ImGui::End();
    }
}

void GUIEditor::footer()
{
    int zoom = 100;
    bool p_open;
    ImGuiWindowClass window_class;
    window_class.DockNodeFlagsOverrideSet = ImGuiDockNodeFlags_AutoHideTabBar;
    window_class.DockNodeFlagsOverrideSet = ImGuiDockNodeFlags_NoResize;
    
    ImGui::SetNextWindowClass(&window_class);
    ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse;

    if (!ImGui::Begin("Footer", &p_open, window_flags))
    {
        ImGui::End();
    } else
    {
        ImGui::SetWindowSize(ImVec2(90, 5));
        ImGui::PushItemWidth(50.0f);
        ImGui::DragInt("##", &zoom, 10, 10, 1000, "%i%%");
        ImGui::End();
    }
}

void GUIEditor::show_layers()
{

    ImVec2 layer_preview_size(40, 40);
    auto layer_list = PhotoEngine::Application::get()->get_layer_list();

    for (auto it = layer_list->end(); it-- != layer_list->begin();)
    {
        // Layer info
        auto layer = (*it);
        int layer_index = (it - layer_list->begin());
        const char* layer_name = layer->get_name().c_str();

        int selected_layer = layer_list->get_selected();

        if (layer_index == layer_list->get_selected()) 
        {
            layer->set_selected(true);
            ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.26f, 0.26f, 0.26f, 1.00f));
        }
        else
        {
            layer->set_selected(false);
        }

        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
        ImGui::BeginChild(layer_name, ImVec2(ImGui::GetWindowSize().x - 15, 50), true);
        if (ImGui::IsWindowHovered() && ImGui::IsMouseClicked(ImGuiMouseButton_Left)) { selected_layer = layer_index; }
        ImGui::SetCursorPos(ImVec2(5, (ImGui::GetWindowSize().y - layer_preview_size.y) * 0.5f));
        ImGui::Image((ImTextureID)layer->get_image()->texture_id, layer_preview_size, ImVec2(1, 0), ImVec2(0, 1));
        ImGui::SameLine();

        // ImGui::SetCursorPos(ImVec2(layer_preview_size.x + 20, (ImGui::GetWindowSize().y - ImGui::GetFontSize()) * 0.5f));
        ImGui::Text("%s", layer_name);
        ImGui::SameLine();
        
        if (ImGui::ImageButton(nullptr, ImVec2(15, 15), ImVec2(0, 1), ImVec2(1, 0))) { layer->toggle_visibility(); }
        ImGui::PopStyleVar();
        ImGui::EndChild();

        if (layer_index == layer_list->get_selected())
        { 
            ImGui::PopStyleColor();
        }
        
        layer_list->set_selected(selected_layer);
    }
}