#pragma once
#include <Toybox.h>

namespace Editor
{
    class EditorCore : public Toybox::Application
    {
    public:
        EditorCore() : Application("Toybox") { }
        ~EditorCore() override = default;

    protected:
        void OnOpen() override
        {
            TBX_TRACE("OnOpen called!");
        }

        void OnUpdate() override
        {
            TBX_INFO("Update called!");
            TBX_WARN(std::format("Frame: {}", _frameCount++));
            GetMainWindow()->Update();
        }

        void OnClose() override
        {
            TBX_TRACE("OnClose called!");
        }

    private:
        int _frameCount = 0;
    };
}

Toybox::Application* Toybox::CreateApp()
{
    TBX_INFO("Created app!");
    return new Editor::EditorCore();
}