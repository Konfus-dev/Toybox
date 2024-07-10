#pragma once

namespace Toybox::Math
{
    struct TOYBOX_API Vector2
    {
        float X, Y;

        Vector2(float x, float y)
        {
            X = x;
            Y = y;
        }
    };
}
