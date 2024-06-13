#include <Toybox.h>

class SandboxApp : public Toybox::Application
{
public:
    SandboxApp() : Application("APP") { }
    ~SandboxApp() override = default;

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

Toybox::Application* Toybox::CreateApp()
{
    return new SandboxApp();
}
