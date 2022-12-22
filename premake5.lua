outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["spdlog"] = "%{wks.location}/3rd Party/spdlog/include"
IncludeDir["glfw"] = "%{wks.location}/3rd Party/glfw/include"
IncludeDir["bgfx"] = "%{wks.location}/3rd Party/bgfx/include"
IncludeDir["bimg"] = "%{wks.location}/3rd Party/bimg/include"
IncludeDir["bx"] = "%{wks.location}/3rd Party/bx/include"
IncludeDir["Engine"] = "%{wks.location}/Engine"

solution "Toybox"
    startproject "Sandbox"

	if os.is64bit() and not os.istarget("windows") then
		platforms "x86_64"
	else
		platforms { "x86", "x86_64" }
	end
    
    -- Configurations
	configurations 
	{ 
		"Dist",
		"Release", 
		"Debug" 
	}
	
	filter "configurations:Dist"
		optimize "On"
		symbols "Off"

	filter "configurations:Release"
		optimize "On"
		symbols "On"

	filter "configurations:Debug"
		optimize "Debug"
		symbols "On"
        
    -- Platforms
	filter "platforms:x86"
		architecture "x86"

	filter "platforms:x86_64"
		architecture "x86_64"

	filter "system:macosx"
		xcodebuildsettings 
		{
			["MACOSX_DEPLOYMENT_TARGET"] = "10.9",
			["ALWAYS_SEARCH_USER_PATHS"] = "YES" -- This is the minimum version of macos we'll be able to run on
		}
	
	-- Project Groups
	group "Dependencies"
		include "3rd Party/bgfx"
		include "3rd Party/glfw"
		include "3rd Party/spdlog"

	group "Core"
		include "Engine"

	group "Testing"
		include "Sandbox"
