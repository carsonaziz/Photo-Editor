#pragma once

#include "event.h"

#include <sstream>

namespace PhotoEngine
{
    class MouseButtonEvent : public Event
    {
    protected:
        unsigned int m_button;

    public:
        MouseButtonEvent(unsigned int button) : m_button(button) {}
    };

    class MouseButtonPressedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonPressedEvent(unsigned int button) : MouseButtonEvent(button) {}

        static EventType get_static_type() {return EventType::MouseButtonPressed; }
        virtual EventType get_type() const override { return get_static_type(); }

        virtual std::string to_string() const override 
        {
            std::stringstream ss;
            ss << "MouseButtonPressed: button: " << m_button;
            return ss.str();
        }
    };

    class MouseButtonReleasedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonReleasedEvent(unsigned int button) : MouseButtonEvent(button) {}

        static EventType get_static_type() {return EventType::MouseButtonReleased; }
        virtual EventType get_type() const override { return get_static_type(); }

        virtual std::string to_string() const override 
        {
            std::stringstream ss;
            ss << "MouseButtonReleased: button: " << m_button;
            return ss.str();
        }
    };

    class MouseMovedEvent : public Event
    {
    private:
        int m_x, m_y;

    public:
        MouseMovedEvent(int x, int y) {}

        static EventType get_static_type() {return EventType::MouseMoved; }
        virtual EventType get_type() const override { return get_static_type(); }
        virtual std::string to_string() const override 
        {
            std::stringstream ss;
            ss << "MouseMoved: x: " << m_x << " y: " << m_y;
            return ss.str();
        }
    };  

    class MouseMovedEvent : public Event
    {
    private:
        int m_offsetx, m_offsety;

    public:
        MouseMovedEvent(int offsetx, int offsety) {}

        static EventType get_static_type() {return EventType::MouseScrolled; }
        virtual EventType get_type() const override { return get_static_type(); }
        virtual std::string to_string() const override 
        {
            std::stringstream ss;
            ss << "MouseScrolled: offsetx: " << m_offsetx << " offsety: " << m_offsety;
            return ss.str();
        }
    };  
}