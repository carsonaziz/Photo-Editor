#include "photoengine/image.h"

#include "photoengine/log.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <glad/glad.h>

namespace PhotoEngine
{
    Image::Image(int width, int height, int r, int g, int b)
        : Width(width), Height(height), Channels(4)
    {
        Data = new unsigned char[Width * Height * Channels];
        for (int i = 0; i < width * height; i++)
        {
            Data[i * 4 + 0] = r;
            Data[i * 4 + 1] = g;
            Data[i * 4 + 2] = b;
            Data[i * 4 + 3] = 255;
        }
    }

    Image::Image(std::string file)
    {
        stbi_set_flip_vertically_on_load(true);
        Data = stbi_load(file.c_str(), &Width, &Height, &Channels, 0);
    }

    Image::~Image()
    {
        delete[] Data;
    }

    void Image::generate_texture()
    {
        glGenTextures(1, &texture_id);
        glBindTexture(GL_TEXTURE_2D, texture_id);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, Width,  Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, Data);
        glBindTexture(GL_TEXTURE_2D, 0);
    }
}