#pragma once

namespace PhotoEngine
{
    class GUIInterface
    {
    public:
        GUIInterface();
        virtual ~GUIInterface();

        void begin();
        void end();

        virtual void render() {}

        static void style_colors_dark();
    };
}