OutputDir = "Build/"

IncludeDir = {}
IncludeDir["spdlog"] = "%{wks.location}/3rd Party/spdlog/include"
IncludeDir["glfw"] = "%{wks.location}/3rd Party/glfw/include"
IncludeDir["Engine"] = "%{wks.location}/Engine/Core"
IncludeDir["EditorCore"] = "%{wks.location}/Editor/Core"

-- Easy way to add supported platforms and standard configs
function StandardPlatformsAndConfigs()
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
end

-- Easy way to link Engine
function IncludeEngine()
    includedirs
    {
        "%{IncludeDir.Engine}"
    }

    links
    {
        "Core"
    }
end

workspace "Toybox"
	architecture "x86_64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Optimized",
		"Release"
	}

	group "_Dependencies"
		include "3rd Party/glfw"
		include "3rd Party/spdlog"
	
	group "Engine"
		include "Engine/Core"
		include "Engine/Modules"
		
	group "Editor"
		include "Editor/Interop"
		externalproject "Sharp"
		   location "Editor/Sharp"
		   kind "WindowedApp"
		   language "C#"

	group "Testing"
		include "Sandbox"
