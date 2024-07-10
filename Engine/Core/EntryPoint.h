#pragma once

#include "Debug/Logging/Logging.h"
#include "Application/App.h"

int main(int argc, char* argv[])
{
    TBX_INFO("Creating app...");
    Toybox::Application::App* app = Toybox::Application::CreateApp();
    app->Launch();
    while (app->IsRunning())
    {
        app->Update();
    }

    TBX_INFO("Deleting app...");
    delete app;
    return 0;
}
