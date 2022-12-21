#pragma once
#include "Application.h"

int main(int argc, char* argv[])
{
    const auto app = Toybox::CreateApp();
    app->Launch();
    delete app;

    return 0;
}
