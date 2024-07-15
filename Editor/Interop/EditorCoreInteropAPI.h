#pragma once

#ifdef TBX_PLATFORM_WINDOWS
    #ifdef TBX_EDITOR_CORE_EXPORT_DLL
        #ifdef TOYBOX_EDITOR
            #define TBX_EDITOR_CORE_INTEROP_API __declspec(dllexport)
        #else
            #define TBX_EDITOR_CORE_INTEROP_API __declspec(dllimport)
        #endif
    #else
        #define TOYBOX_API
    #endif
#else
    #define TOYBOX_API
#endif
