#pragma once

#include "IWindow.h"
#include "WindowMode.h"

namespace Toybox::Application
{
    class GlfwWindow : public IWindow
    {
    public:
        GlfwWindow(const std::string& title, Math::Size* size, WindowMode mode);
        ~GlfwWindow();

        void Update() override;

        void SetVSyncEnabled(bool enabled) override;
        bool GetVSyncEnabled() const override;

        void SetSize(Math::Size* size) override;
        Math::Size* GetSize() const override;

        std::string GetTitle() const override;
        Math::uint64 GetId() const override;

        void SetEventCallback(const EventCallbackFn& callback) override;
        void SetMode(WindowMode mode) override;

    private:
        std::string _title;
        Math::Size* _size;
        bool _vSyncEnabled;
        EventCallbackFn _eventCallback;

        void SetupCallbacks();
        void SetupContext();
    };
}
