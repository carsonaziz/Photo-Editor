#pragma once

#include "photoengine/events/event.h"

namespace PhotoEngine
{
    class Layer
    {
    public:
        virtual ~Layer() {}

        virtual void on_attach() = 0;
        virtual void on_detach() = 0;

        virtual void on_event(Event& event) = 0;
        virtual void update() = 0;
        virtual void render() const = 0;
    };
}