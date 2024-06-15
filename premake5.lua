OutputDir = "Build/"

IncludeDir = {}
IncludeDir["spdlog"] = "%{wks.location}/3rd Party/spdlog/include"
IncludeDir["glfw"] = "%{wks.location}/3rd Party/glfw/include"
IncludeDir["Engine"] = "%{wks.location}/Engine"
IncludeDir["EditorCoreLib"] = "%{wks.location}/Editor/Editor Core Lib"

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
        "Engine"
    }
end

-- Easy way to link EditorCore
function IncludeEditorCoreLib()
    includedirs
    {
        "%{IncludeDir.EditorCoreLib}",
    }

    links
    {
        "EditorCoreLib",
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
		include "Engine"
		
	group "Editor"
		include "Editor/Editor Core"
		include "Editor/Editor Core Lib"
		include "Editor/Editor Core Interop"
		externalproject "EditorSharp"
		   location "Editor/Editor Sharp"
		   kind "WindowedApp"
		   language "C#"

	group "Testing"
		include "Sandbox"
