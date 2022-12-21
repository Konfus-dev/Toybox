#pragma once

namespace Toybox::Math
{
    struct Size
    {
        unsigned int Width, Height;

        Size(unsigned int width, unsigned int height)
        {
            Width = width;
            Height = height;
        }
    };
}