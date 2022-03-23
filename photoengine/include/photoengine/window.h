#pragma once

#include "photoengine/events/event.h"
#include <string>

struct GLFWwindow;

namespace PhotoEngine
{
    struct WindowProps
    {
        std::string Title;
        unsigned int Width, Height;

        WindowProps(const std::string& title = "PhotoEditor", unsigned int width = 1280, unsigned int height = 800)
            : Title(title), Width(width), Height(height) {}
    };

    class Window
    {
    private:
        struct WindowData
        {
            std::string Title;
            unsigned int Width, Height;
            bool Vsync;
            std::function<void(Event& e)> Eventcallback;
        };

        GLFWwindow* m_window;
        WindowData m_data;

    private:
        void init(const WindowProps& props);

        static void error_callback_fn(int error_code, const char* description);
    public:
        Window(const WindowProps& props = WindowProps());
        ~Window();

        void set_event_callback(const std::function<void(Event& e)>& callback);
        void update();
        void shutdown();

        void set_vsync(bool vsync);
    };
}