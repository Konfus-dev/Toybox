project "Engine"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"
    staticruntime "Off"

    targetdir ("../Build/bin/" .. outputdir .. "/%{prj.name}")
    objdir    ("../Build/obj/" .. outputdir .. "/%{prj.name}")

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

    filter "configurations:Release"
        runtime "Release"
        optimize "On"
        symbols "On"
        defines
        {
            "TBX_RELEASE"
        }
    
    filter "configurations:Dist"
        runtime "Release"
        optimize "On"
        symbols "Off"
        defines 
        {
            "TBX_DIST"
        }

    -- Platforms
    filter "system:Windows"
        systemversion "latest"
        defines
        {
            "TBX_PLATFORM_WINDOWS"
        }

    filter "system:Linux"
        systemversion "latest"
        defines
        {
            "TBX_PLATFORM_LINUX"
        }

    filter "system:Macosx"
        systemversion "latest"
        defines
        {
            "TBX_PLATFORM_OSX"
        }