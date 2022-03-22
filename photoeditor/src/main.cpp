#include "entry_point.h"

class PhotoEditor : public PhotoEngine::Application
{
public:
    PhotoEditor()
    {

    }

    ~PhotoEditor()
    {

    }
};

PhotoEngine::Application* PhotoEngine::create()
{
    return new PhotoEditor();
}