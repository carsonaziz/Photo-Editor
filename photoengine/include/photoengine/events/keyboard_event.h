#pragma once

#include "event.h"

#include <sstream>

namespace PhotoEngine
{
    class KeyEvent : public Event
    {
    protected:
        unsigned int m_keycode;

    public:
        KeyEvent(unsigned int keycode) : m_keycode(keycode) {}
    };

    class KeyPressedEvent : public KeyEvent
    {
    private:
        unsigned int m_repeat_count;
    public:
        KeyPressedEvent(unsigned int keycode, unsigned int repeat_count) : KeyEvent(keycode) 
        {
            m_repeat_count = repeat_count;
        }

        static EventType get_static_type() {return EventType::KeyPressed; }
        virtual EventType get_type() const override { return get_static_type(); }

        inline unsigned int get_repeat_count() { return m_repeat_count; }

        virtual std::string to_string() const override 
        {
            std::stringstream ss;
            ss << "KeyPressed: keycode: " << m_keycode << " repeats: " << m_repeat_count;
            return ss.str();
        }
    };

    class KeyReleasedEvent : public KeyEvent
    {
    public:
        KeyReleasedEvent(unsigned int keycode) : KeyEvent(keycode) {}

        static EventType get_static_type() {return EventType::KeyReleased; }
        virtual EventType get_type() const override { return get_static_type(); }
        virtual std::string to_string() const override 
        {
            std::stringstream ss;
            ss << "KeyReleased: keycode " << m_keycode;
            return ss.str();
        }
    };

    class KeyTypedEvent : public KeyEvent
    {
    public:
        KeyTypedEvent(unsigned int keycode) : KeyEvent(keycode) {}

        static EventType get_static_type() {return EventType::KeyTyped; }
        virtual EventType get_type() const override { return get_static_type(); }
        virtual std::string to_string() const override 
        {
            std::stringstream ss;
            ss << "KeyTyped: keycode " << m_keycode;
            return ss.str();
        }
    };    
}