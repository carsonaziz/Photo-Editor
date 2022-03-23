#pragma once

#include <string>
#include <ostream>

namespace PhotoEngine
{
    enum class EventType
    {
        WindowClose, WindowResize, WindowFocus, WindowMoved,
        KeyPressed, KeyReleased, KeyTyped,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
    };

    class Event
    {
    public:
        bool m_handled = false;

    public:
        virtual EventType get_type() const = 0;
        virtual std::string to_string() const = 0;
    };

    class EventHandler
    {
    private:
        Event& m_event;

    public:
        EventHandler(Event& event) : m_event(event) {}

        template<typename T>
        bool handle_event(std::function<bool(T&)> fn)
        {
            if (m_event.get_type() == T::get_static_type())
            {
                m_event.m_handled = fn(*(T*)&m_event);
                return true;
            }
            return false;
        }
    };

    inline std::ostream& operator<<(std::ostream& os, const Event& event)
    {
        return os << event.to_string();
    }
}