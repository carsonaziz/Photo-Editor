#pragma once

#include <string>

namespace PhotoEngine
{
    struct Image
    {
        unsigned int texture_id;

        unsigned char* Data;
        int Width, Height, Channels;

        Image(int width, int height, int r = 255, int g = 255, int b = 255);
        Image(std::string file);
        ~Image();

        void generate_texture();
    };
}