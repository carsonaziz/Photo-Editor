#include "photoengine/layers/imgui_layer.h"

#include "photoengine/log.h"
#include "photoengine/events/mouse_event.h"

namespace PhotoEngine
{
    void ImGUILayer::on_event(Event& event)
    {
        EventHandler handler(event);
        handler.handle_event<MouseButtonPressedEvent>(std::bind(&ImGUILayer::mouse_button_pressed, this, std::placeholders::_1));
    }

    void ImGUILayer::update()
    {

    }

    void ImGUILayer::render() const
    {

    }

    bool ImGUILayer::mouse_button_pressed(Event& event)
    {
        PE_ENGINE_TRACE("{}", event.to_string());

        return true;
    }
}