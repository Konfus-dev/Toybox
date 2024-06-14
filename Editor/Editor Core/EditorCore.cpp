#include <Toybox.h>
#include "EditorCoreAPI.h"

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
    
    Toybox::Application* CoreApp;
    
    TBX_EDITOR_CORE_API int LaunchViewport()
    {
        TBX_INFO("Launching Editor!");
        CoreApp = Toybox::CreateApp();
        CoreApp->Launch();
        return CoreApp->GetHandle();
    }

    TBX_EDITOR_CORE_API void UpdateViewport()
    {
        TBX_INFO("Updating viewport!");
        CoreApp->GetMainWindow()->Update();
    }
}

Toybox::Application* Toybox::CreateApp()
{
    TBX_INFO("Created app!");
    return new Editor::EditorCore();
}