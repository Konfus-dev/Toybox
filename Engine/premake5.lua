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
		files
		{
			"src/win32_*.*",
			"src/wgl_context.*"
		}
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
            "TBX_PLATFORM_WINDOWS",
            "_GLFW_WIN32"
        }

    filter "system:linux"
		files
		{
			"src/glx_context.*",
			"src/linux*.*",
			"src/posix*.*",
			"src/x11*.*",
			"src/xkb*.*"
		}
        links 
        { 
            "dl", 
            "GL", 
            "pthread", 
            "X11" 
        }
        defines
        {
            "_GLFW_X11"
        }

    filter "system:macosx"
		files
		{
			"src/cocoa_*.*",
			"src/posix_thread.h",
			"src/nsgl_context.h",
			"src/egl_context.h",
			"src/osmesa_context.h",

			"src/posix_thread.c",
			"src/nsgl_context.m",
			"src/egl_context.c",
			"src/nsgl_context.m",
			"src/osmesa_context.c"                      
		}
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
        defines
        {
            "_GLFW_COCOA"
        }