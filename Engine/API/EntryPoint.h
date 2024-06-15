#pragma once
#include "Application.h"
#include "Debug/Logging/Logging.h"

int main(int argc, char* argv[])
{
    TBX_INFO("Creating app...");
    Toybox::Application* app = Toybox::CreateApp();
    app->Launch();
    while (app->GetIsRunning())
    {
        TBX_INFO("Updating app...");
        app->Update();
    }

    TBX_INFO("Deleting app...");
    delete app;
    return 0;
}
