#include "photoengine/layers/layer_list.h"

namespace PhotoEngine
{
    void LayerList::insert(Layer* layer, unsigned int index)
    {
        m_layers.insert(m_layers.begin() + index, layer);
        layer->on_attach();
    }

    void LayerList::remove(unsigned int index)
    {
        m_layers[index]->on_detach();
        m_layers.erase(m_layers.begin() + index);
    }

    void LayerList::move(unsigned int from, unsigned int to)
    {
        std::iter_swap(m_layers.begin() + from, m_layers.begin() + to);
    }
}