project "Engine"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"
    staticruntime "Off"
    
    targetdir ("../Build/bin/" .. outputdir .. "/%{prj.name}/")
    objdir    ("../Build/obj/" .. outputdir .. "/%{prj.name}/")

    pchheader "tbxpch.h"
    pchsource "tbxpch.cpp"

    defines
    {
        "TOYBOX"
    }

    files
    {
        "./**.h",
        "./**.c",
        "./**.hpp",
        "./**.cpp"
    }

    includedirs
    {
        "./",
        "%{IncludeDir.spdlog}",
        "%{IncludeDir.glfw}"
    }

    links
    {
        "spdlog",
        "glfw",
        "opengl32.lib",
        "dwmapi.lib"
    }

    -- Disable warnings on all 3rd party stuff
    filter "files:../3rd Party/*"
        disablewarnings { "warning" }

    -- Configurations
    filter "configurations:Debug"
        runtime "Debug"
        optimize "On"
        symbols "On"
        defines
        {
            "TBX_DEBUG",
            "TBX_ASSERTS_ENABLED"
        }

    filter "configurations:Optimized"
        runtime "Release"
        optimize "On"
        symbols "On"
        defines
        {
            "TBX_OPTIMIZED"
        }
    
    filter "configurations:Dist"
        runtime "Release"
        optimize "On"
        symbols "Off"
        defines 
        {
            "TBX_RELEASE"
        }

    -- Platforms
    filter "system:Windows"
        systemversion "latest"
        defines
        {
            "TBX_PLATFORM_WINDOWS",
            "GLFW_EXPOSE_NATIVE_WIN32"
        }

    filter "system:Linux"
        systemversion "latest"
        defines
        {
            "TBX_PLATFORM_LINUX",
            "GLFW_EXPOSE_NATIVE_WAYLAND"
        }

    filter "system:Macosx"
        systemversion "latest"
        defines
        {
            "TBX_PLATFORM_OSX",
            "GLFW_EXPOSE_NATIVE_COCOA"
        }