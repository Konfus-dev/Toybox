#include <Toybox.h>

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

    TOYBOX_API int LaunchEditorCore()
    {
        TBX_INFO("Loading Engine!");
        Toybox::Application* editorCore = Toybox::CreateApp();
        return editorCore->GetHandle();
    }
}

Toybox::Application* Toybox::CreateApp()
{
    return new Editor::EditorCore();
}
