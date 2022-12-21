#include <Toybox.h>
#include <GL/gl.h>

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
        glClearColor(1, 0, 1, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        TBX_INFO("Update called!");
        TBX_WARN(fmt::format("Frame: {}", _frameCount++));
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
