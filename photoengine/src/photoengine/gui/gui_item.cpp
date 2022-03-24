#include "photoengine/gui/gui_item.h"

#include "imgui.h"

namespace PhotoEngine
{
    void GUIAdjustment::render()
    {
        ImGuiWindowFlags window_flags = 0;
        ImGui::Begin("Adjustments", &p_open, window_flags);

        ImGui::End();
    }

    void GUIColor::render()
    {
        ImGuiWindowFlags window_flags = 0;
        ImGui::Begin("Color", &p_open, window_flags);

        ImGui::End();
    }

    void GUILayer::render()
    {
        ImGuiWindowFlags window_flags = 0;
        ImGui::Begin("Layers", &p_open, window_flags);

        ImGui::End();
    }

    void GUITool::render()
    {
        ImGuiWindowClass window_class;
        window_class.DockNodeFlagsOverrideSet = ImGuiDockNodeFlags_AutoHideTabBar;
        window_class.DockNodeFlagsOverrideSet = ImGuiDockNodeFlags_NoResize;
        ImGui::SetNextWindowClass(&window_class);
        ImGuiWindowFlags window_flags = 0;
        
        ImGui::Begin("Tools", &p_open, window_flags);

        ImGui::End();
    }

    void GUIFooter::render()
    {
        bool p_open = true;
        ImGuiWindowClass window_class;
        window_class.DockNodeFlagsOverrideSet = ImGuiDockNodeFlags_AutoHideTabBar;
        window_class.DockNodeFlagsOverrideSet = ImGuiDockNodeFlags_NoResize;
        ImGui::SetNextWindowClass(&window_class);
        ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse;

        ImGui::Begin("Footer", &p_open, window_flags);
        ImGui::SetWindowSize(ImVec2(90, 5));
        ImGui::PushItemWidth(50.0f);
        // ImGui::DragInt("##", &zoom, 10, 10, 1000, "%i%%");

        ImGui::End();
    }

    void GUIViewport::render()
    {
        bool p_open = true;
        ImGuiWindowFlags window_flags = 0;
        window_flags |= ImGuiWindowFlags_HorizontalScrollbar;
        ImGui::Begin("Viewport", &p_open, window_flags);

        float xsize = 700, ysize = 700;
        ImVec2 image_zoom_size = ImVec2(700, 700);
        // ImVec2 image_zoom_size = ImVec2(xsize * ((float)zoom/100.0f), ysize * ((float)zoom/100.0f));
        ImGui::SetCursorPos(ImVec2((ImGui::GetWindowSize().x - image_zoom_size.x)*0.5f, (ImGui::GetWindowSize().y - image_zoom_size.y)*0.5f));
        ImGui::Image(0, image_zoom_size, ImVec2(0, 1), ImVec2(1, 0));

        ImGui::End();
    }
}