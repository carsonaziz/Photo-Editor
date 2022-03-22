#include "entry_point.h"

#include <iostream>

class PhotoEditor : public PhotoEngine::Application
{
public:
    PhotoEditor()
    {
        std::cout << "Inside PhotoEditor\n";
    }

    ~PhotoEditor()
    {

    }
};

PhotoEngine::Application* PhotoEngine::create()
{
    return new PhotoEditor();
}