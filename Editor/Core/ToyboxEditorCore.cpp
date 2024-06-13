#include <Toybox.h>
#include "ToyboxEditorAPI.h"

namespace Editor
{
    class EditorCore : public Toybox::Application
    {
    public:
        EditorCore() : Application("Toybox") { }
        ~EditorCore() override = default;

        int Start()
        {
            TBX_INFO("Loading Engine!");
            return GetHandle();
        }

    protected:
        void OnOpen() override
        {
            TBX_TRACE("OnOpen called!");
        }

        void Update() override
        {
            TBX_INFO("Update called!");
            TBX_WARN(std::format("Frame: {}", _frameCount++));
        }

        void OnClose() override
        {
            TBX_TRACE("OnClose called!");
        }

    private:
        int _frameCount = 0;
    };
}

TBX_EDITOR_API int LaunchViewport()
{
    Toybox::Application* editorCore = Toybox::CreateApp();
    return editorCore->GetHandle();
}

Toybox::Application* Toybox::CreateApp()
{
    return new Editor::EditorCore();
}
