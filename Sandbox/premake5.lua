project "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "On"

    targetdir ("../Build/bin/" .. outputdir .. "/%{prj.name}")
    objdir    ("../Build/obj/" .. outputdir .. "/%{prj.name}")

    files
    {
        "./**.h",
        "./**.c",
        "./**.hpp",
        "./**.cpp"
    }

    includedirs
    {
        "%{IncludeDir.Engine}",
        "%{IncludeDir.spdlog}",
        "%{IncludeDir.glfw}",
        "%{IncludeDir.bgfx}"
    }

    links
    {
        "Engine"
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
        links 
        { 
            "dl", 
            "GL", 
            "pthread", 
            "X11" 
        }
        defines
        {
            "TBX_PLATFORM_LINUX"
        }

    filter "system:macosx"
        systemversion "latest"
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
            "TBX_PLATFORM_OSX"
        }
    
    -- Configurations
    filter "configurations:Debug"
        systemversion "latest"
        symbols "On"
        defines
        {
            "TBX_DEBUG",
            "TBX_ASSERTS_ENABLED"
        }

    filter "configurations:Release"
        optimize "On"
        symbols "On"
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