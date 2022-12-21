#pragma once
#include "EventCategory.h"
#include "../API/ToyboxAPI.h"

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