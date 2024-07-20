#include <Toybox.h>

class SandboxApp : public Toybox::Application::App
{
public:
    SandboxApp() : App("Sandbox") { }
    ~SandboxApp() override = default;

protected:
    void OnOpen() override
    {
        //TBX_TRACE("OnOpen called!");
    }

    void OnUpdate() override
    {
        //TBX_INFO("Update called!");
        //TBX_WARN("Frame: {}", _frameCount++);
    }

    void OnClose() override
    {
        //TBX_TRACE("OnClose called!");
    }

private:
    int _frameCount = 0;
};

Toybox::Application::App* Toybox::Application::CreateApp()
{
    return new SandboxApp();
}
