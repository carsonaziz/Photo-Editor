#include "entry_point.h"

#include "gui/gui_editor.h"
#include "photoengine/layers/layer.h"

class PhotoEditor : public PhotoEngine::Application
{
public:
    PhotoEditor()
    {
        m_layer_list->insert(new PhotoEngine::Layer(500, 500, "Layer 0"), 0);
        m_layer_list->insert(new PhotoEngine::Layer(500, 500, "Layer 1", 51, 77, 204), 1);
        m_layer_list->insert(new PhotoEngine::Layer(500, 500, "Layer 2", 51, 204, 77), 2);
        m_gui_interface = std::make_unique<GUIEditor>();
    }

    ~PhotoEditor()
    {

    }
};

PhotoEngine::Application* PhotoEngine::create()
{
    return new PhotoEditor();
}