outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["spdlog"] = "%{wks.location}/3rd Party/spdlog/include"
IncludeDir["glfw"] = "%{wks.location}/3rd Party/glfw/include"
IncludeDir["bgfx"] = "%{wks.location}/3rd Party/bgfx/include"
IncludeDir["bimg"] = "%{wks.location}/3rd Party/bimg/include"
IncludeDir["bx"] = "%{wks.location}/3rd Party/bx/include"
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
	
	-- Project Groups
	group "Dependencies"
		include "3rd Party/bgfx"
		include "3rd Party/glfw"
		include "3rd Party/spdlog"

	group "Core"
		include "Engine"

	group "Testing"
		include "Sandbox"
