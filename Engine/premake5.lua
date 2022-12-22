project "Engine"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
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
        "%{IncludeDir.glfw}",
        "%{IncludeDir.bgfx}"
    }

    links
    {
        "spdlog",
        "glfw",
        "bgfx",
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
    filter "system:windows"
        systemversion "latest"
        defines
        {
            "TBX_PLATFORM_WINDOWS"
        }

    filter "system:linux"
        systemversion "latest"
        defines
        {
            "TBX_PLATFORM_LINUX"
        }

    filter "system:macosx"
        systemversion "latest"
        defines
        {
            "TBX_PLATFORM_OSX"
        }