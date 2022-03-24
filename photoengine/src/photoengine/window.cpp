#include "photoengine/window.h"

#include "photoengine/log.h"
#include "photoengine/events/window_event.h"
#include "photoengine/events/keyboard_event.h"
#include "photoengine/events/mouse_event.h"

#include <glad/glad.h>
#include <glfw/glfw3.h>

namespace PhotoEngine
{
    Window::Window(const WindowProps& props)
    {
        init(props);
    }

    Window::~Window()
    {

    }

    void Window::init(const WindowProps& props)
    {
        m_data.Title = props.Title;
        m_data.Width = props.Width;
        m_data.Height = props.Height;
        m_data.Vsync = true;

        int success = glfwInit();
        if (!success)
        {
            PE_ENGINE_ERROR("Could not initialize glfw!");
            return;
        }

        glfwSetErrorCallback(error_callback_fn);

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, true);

        m_window = glfwCreateWindow(props.Width, props.Height, props.Title.c_str(), nullptr, nullptr);
        if (!m_window)
        {
            PE_ENGINE_ERROR("Could not create GLFWwindow!");
            return;
        }
        PE_ENGINE_INFO("Created window {}: w: {} h: {}", m_data.Title, m_data.Width, m_data.Height);

        glfwMakeContextCurrent(m_window);
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            PE_ENGINE_ERROR("Failed to initialzie GLAD");
        }

        glfwSetWindowUserPointer(m_window, &m_data);
        set_vsync(false);

        // Window Callbacks
        glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            data.Width = width;
            data.Height = height;

            WindowResizeEvent event(width, height);
            data.Eventcallback(event);
        });

        glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            WindowCloseEvent event;
            data.Eventcallback(event);
        });

        // Key Callbacks
        glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            switch (action)
            {
                case GLFW_PRESS:
                {
                    KeyPressedEvent event(key, 0);
                    data.Eventcallback(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    KeyReleasedEvent event(key);
                    data.Eventcallback(event);
                    break;
                }
                case GLFW_REPEAT:
                {
                    KeyPressedEvent event(key, 1);
                    data.Eventcallback(event);
                    break;
                }
            }
        });

        // Mouse Callbacks
        glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double xpos, double ypos)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            MouseMovedEvent event(xpos, ypos);
            data.Eventcallback(event);
        });

        glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mods)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            switch (action)
            {
                case GLFW_PRESS:
                {
                    MouseButtonPressedEvent event(button);
                    data.Eventcallback(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    MouseButtonReleasedEvent event(button);
                    data.Eventcallback(event);
                    break;
                }
            }
        });

        glfwSetScrollCallback(m_window, [](GLFWwindow* window, double xoffset, double yoffset)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            MouseScrolledEvent event(xoffset, yoffset);
            data.Eventcallback(event);
        });
    }

    void Window::update()
    {
        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }

    void Window::shutdown()
    {
        glfwDestroyWindow(m_window);
    }

    void Window::set_vsync(bool vsync)
    {
        if (vsync)
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);

        m_data.Vsync = vsync;
    }

    void Window::set_event_callback(const std::function<void(Event& e)>& callback)
    {
        m_data.Eventcallback = callback;
    }

    void Window::error_callback_fn(int error_code, const char* description)
    {
        PE_ENGINE_ERROR("GLFWerror {}: {}", error_code, description);
    }
}