project "Engine"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"
    staticruntime "Off"
    
    targetdir ("../" .. OutputDir .. "/bin/%{prj.name}/")
    objdir    ("../" .. OutputDir .. "/obj/%{prj.name}/")

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

    -- Setup standard platforms and configs
    StandardPlatformsAndConfigs()

    -- Expose native platform methods 
	-- which is needed to grab handles of windows for editor
    filter "system:Windows"
        defines
        {
			"TBX_EXPORT_DLL",
            "GLFW_EXPOSE_NATIVE_WIN32"
        }

    filter "system:Linux"
        defines
        {
            "GLFW_EXPOSE_NATIVE_WAYLAND"
        }

    filter "system:Macosx"
        defines
        {
            "GLFW_EXPOSE_NATIVE_COCOA"
        }