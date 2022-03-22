#pragma once

#include "photoengine/application.h"
#include "photoengine/log.h"

extern PhotoEngine::Application* PhotoEngine::create();

int main(int argc, char** argv)
{
    PhotoEngine::Log::init();
    PE_ENGINE_INFO("Logger Initialized");

    auto app = PhotoEngine::create();
    app->run();
    delete app;
}