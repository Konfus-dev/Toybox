#pragma once
#include "tbxpch.h"
#include "API/ToyboxAPI.h"
#include "Events/Event.h"
#include "Math/Size.h"

namespace Toybox::Modules
{
    class TOYBOX_API IWindow
    {
    public:
        using EventCallbackFn = std::function<void(Events::Event&)>;
        virtual ~IWindow() = default;
        virtual void Update() = 0;
        
        virtual void SetVSyncEnabled(bool enabled) = 0;
        virtual bool GetVSyncEnabled() const = 0;
        virtual Math::Size* GetSize() const = 0;
        virtual std::string GetTitle() const = 0;
    };
}
