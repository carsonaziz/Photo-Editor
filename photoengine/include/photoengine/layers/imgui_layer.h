#pragma once

#include "layer.h"

namespace PhotoEngine
{
    class ImGUILayer : public Layer
    {
    private:
        bool mouse_button_pressed(Event& event);
    public:
        ImGUILayer() {}
        ~ImGUILayer() {}

        virtual void on_event(Event& event) override;
        virtual void update() override;
        virtual void render() const override;
    };
}