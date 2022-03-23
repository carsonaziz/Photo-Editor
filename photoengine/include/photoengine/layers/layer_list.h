#pragma once

#include "photoengine/layers/layer.h"

#include <vector>

namespace PhotoEngine
{
    class LayerList
    {
    private:
        std::vector<Layer*> m_layers;
        unsigned int m_current_index;

    public:
        LayerList() : m_current_index(0) {}
        ~LayerList() {}

        void insert(Layer* layer, unsigned int index);
        void remove(unsigned int index);
        void move(unsigned int from, unsigned int to);

        inline std::vector<Layer*>::iterator begin() { return m_layers.begin(); }
        inline std::vector<Layer*>::iterator end() { return m_layers.end(); }
    };
}