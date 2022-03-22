#pragma once

namespace PhotoEngine
{
    class Application
    {
    private:
        static Application* s_instance;

    public:
        Application();
        virtual ~Application();

        void run();
    };

    Application* create();
}