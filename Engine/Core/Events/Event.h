#pragma once

#include "ToyboxAPI.h"
#include "EventCategory.h"

#define TBX_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace Toybox::Events
{
    class TOYBOX_API Event
    {
    public:
        virtual ~Event() = default;
        virtual int GetCategorization() const = 0;
        bool IsInCategory(EventCategory category) const
        {
            return GetCategorization() & category;
        }

        bool Handled = false;
    };
}