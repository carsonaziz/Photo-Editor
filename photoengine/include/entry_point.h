#pragma once

#include "photoengine/application.h"

extern PhotoEngine::Application* PhotoEngine::create();

int main(int argc, char** argv)
{
    auto app = PhotoEngine::create();
    app->run();
    delete app;
}