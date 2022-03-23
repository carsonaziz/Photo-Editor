#pragma once

#include "photoengine/events/event.h"

#include <sstream>

namespace PhotoEngine
{
    class WindowCloseEvent : public Event
    {
    public:
        WindowCloseEvent() {}

        static EventType get_static_type() {return EventType::WindowClose; }
        virtual EventType get_type() const override { return get_static_type(); }

        virtual std::string to_string() const override 
        {
            std::stringstream ss;
            ss << "WindowClose";
            return ss.str();
        }
    };

    class WindowResizeEvent : public Event
    {
    private:
        int m_width, m_height;
    public:
        WindowResizeEvent(int width, int height) : m_width(width), m_height(height) {}

        static EventType get_static_type() {return EventType::WindowResize; }
        virtual EventType get_type() const override { return get_static_type(); }

        virtual std::string to_string() const override 
        {
            std::stringstream ss;
            ss << "WindowResize: w: " << m_width << " h: " << m_height;
            return ss.str();
        }
    };

    class WindowFocusEvent : public Event
    {
    public:
        WindowFocusEvent() {}

        static EventType get_static_type() {return EventType::WindowFocus; }
        virtual EventType get_type() const override { return get_static_type(); }

        virtual std::string to_string() const override 
        {
            std::stringstream ss;
            ss << "WindowFocus";
            return ss.str();
        }
    };

    class WindowMovedEvent : public Event
    {
    public:
        WindowMovedEvent() {}

        static EventType get_static_type() {return EventType::WindowMoved; }
        virtual EventType get_type() const override { return get_static_type(); }

        virtual std::string to_string() const override 
        {
            std::stringstream ss;
            ss << "WindowMoved";
            return ss.str();
        }
    };
}