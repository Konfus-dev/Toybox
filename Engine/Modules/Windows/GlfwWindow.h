#pragma once
#include "IWindow.h"

namespace Toybox::Modules
{
    class TOYBOX_API GlfwWindow : public IWindow
    {
    public:
        GlfwWindow(const std::string& title, Math::Size* size);
        ~GlfwWindow() override;
        void Update() override;
        void SetVSyncEnabled(bool enabled) override;
        bool GetVSyncEnabled() const override;
        int GetHandle() const override;
        Math::Size* GetSize() const override;
        std::string GetTitle() const override;

    private:
        std::string _title;
        Math::Size* _size;
        bool _vSyncEnabled;
    };
}
