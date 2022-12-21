project "Engine"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "off"

    targetdir ("Build/bin/" .. outputdir .. "/%{prj.name}")
    objdir    ("Build/obj/" .. outputdir .. "/%{prj.name}")

    pchheader "tbxpch.h"
    pchsource "Engine/tbxpch.cpp"

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
        "Engine",
        "%{IncludeDir.spdlog}",
        "%{IncludeDir.glfw}",
        "%{IncludeDir.bgfx}",
    }

    links
    {
        "spdlog",
        "bgfx", 
        "glfw",
        "opengl32.lib"
    }

    -- Platforms
    filter "system:windows"
        systemversion "latest"
        includedirs 
        { 
            "%{IncludeDir.bgfx}/compat/mingw"
        }
        links 
        { 
            "gdi32", 
            "kernel32", 
            "psapi" 
        }
        defines
        {
            "TBX_PLATFORM_WINDOWS"
        }

    filter "system:linux"
		links 
        { 
            "dl", 
            "GL", 
            "pthread", 
            "X11" 
        }

    filter "system:macosx"
		includedirs 
        { 
            "%{IncludeDir.bgfx}/compat/osx"
        }
		links 
        { 
            "QuartzCore.framework", 
            "Metal.framework", 
            "Cocoa.framework",
            "IOKit.framework",
            "CoreVideo.framework" 
        }

    -- Configurations
	filter "action:vs*"
		includedirs 
        { 
            "%{IncludeDir.bgfx}/compat/msvc"
        }

    filter "configurations:Debug"
		runtime "Debug"
        symbols "On"
        defines
        {
            "TBX_DEBUG",
            "TBX_ASSERTS_ENABLED",
			"BX_CONFIG_DEBUG"
        }

    filter "configurations:Release"
		runtime "Release"
        optimize "On"
        defines
		{
            "TBX_RELEASE"
		}