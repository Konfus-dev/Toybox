outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["spdlog"] = "%{wks.location}/3rd Party/spdlog/include"
IncludeDir["glfw"] = "%{wks.location}/3rd Party/glfw/include"
IncludeDir["Engine"] = "%{wks.location}/Engine"

workspace "Toybox"
	architecture "x86_64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	
	group "Dependencies"
		include "3rd Party/glfw"
		include "3rd Party/spdlog"
		
	group "Editor"
		include "Editor"
	
	group "Engine"
		group "Core"
			include "Engine"
		group "Modules"
			group "Logging"
			group "Rendering"
			group "Windows"

	group "Testing"
		include "Sandbox"
