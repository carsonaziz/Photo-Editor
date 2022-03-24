#pragma once

namespace PhotoEngine
{
    class GUIPanel
    {
    protected:
        bool p_open;
    public:
        GUIPanel() : p_open(true) {}
        virtual ~GUIPanel() {}

        virtual void render() = 0;
    };

    class GUIAdjustment : public GUIPanel
    {
    public:
        GUIAdjustment() : GUIPanel() {}

        virtual void render() override;
    };

    class GUILayer : public GUIPanel
    {
    public:
        GUILayer() : GUIPanel() {}

        virtual void render() override;
    };

    class GUIColor : public GUIPanel
    {
    public:
        GUIColor() : GUIPanel() {}

        virtual void render() override;
    };

    class GUITool : public GUIPanel
    {
    public:
        GUITool() : GUIPanel() {}

        virtual void render() override;
    };

    class GUIFooter : public GUIPanel
    {
    public:
        GUIFooter() : GUIPanel() {}

        virtual void render() override;
    };

    class GUIViewport : public GUIPanel
    {
    public:
        GUIViewport() : GUIPanel() {}

        virtual void render() override;
    };
}