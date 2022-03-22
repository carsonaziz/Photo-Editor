#pragma once

namespace PhotoEngine
{
    class Application
    {
    public:
        Application();
        virtual ~Application();

        void run();
    };

    Application* create();
}