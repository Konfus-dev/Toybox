#pragma once

namespace Toybox::Math
{
    struct TOYBOX_API Size
    {
        int Width, Height;

        Size(int width, int height)
        {
            Width = width;
            Height = height;
        }
    };
}