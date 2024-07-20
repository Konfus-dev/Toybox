#pragma once

#include "Debug/Logging/Logging.h"
#include "Application/App.h"

int main(int argc, char* argv[])
{
    Toybox::Application::App* app = Toybox::Application::CreateApp();
    app->Launch();
    while (app->IsRunning())
    {
        app->Update();
    }

    delete app;
    return 0;
}
