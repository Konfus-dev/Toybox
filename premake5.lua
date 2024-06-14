--outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
outputdir = ""
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
		"Optimized",
		"Release"
	}
	
	group "_Dependencies"
		include "3rd Party/glfw"
		include "3rd Party/spdlog"
	
	group "Engine"
		include "Engine"

	group "Testing"
		include "Sandbox"
