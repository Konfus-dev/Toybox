project "Engine"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "On"

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
        "bgfx"
    }
    
	-- Actions
    filter "action:vs*"
		defines "_CRT_SECURE_NO_WARNINGS"

    -- Configurations
    filter "configurations:Debug"
        defines
        {
            "TBX_DEBUG",
            "TBX_ASSERTS_ENABLED",
            "BX_CONFIG_DEBUG"
        }

    filter "configurations:Release"
        defines
        {
            "TBX_RELEASE"
        }
    
    filter "configurations:Dist"
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
        defines
        {
            "TBX_PLATFORM_LINUX"
        }

    filter "system:macosx"
        defines
        {
            "TBX_PLATFORM_OSX"
        }