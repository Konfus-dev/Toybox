project "Interop"
    kind "SharedLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "Off"
	warnings "Default"

    targetdir ("../../" .. OutputDir .. "/bin/%{prj.name}/")
    objdir    ("../../" .. OutputDir .. "/obj/%{prj.name}/")

    files
    {
        "./**.h",
        "./**.c",
        "./**.hpp",
        "./**.cpp",
        "./**.cs",
    }

    -- Setup standard platforms and configs
	IncludeEngine()
    StandardPlatforms()
    StandardConfigs()
	
	-- Editor Supported Platforms
	filter "system:Windows"
        defines
        {
			"TOYBOX_EDITOR",
			"TBX_EDITOR_CORE_EXPORT_DLL"
		}
	
	-- Needed for .DLL stufffilter "configurations:Debug"
	filter "configurations:Debug"
        buildoptions "/MDd"

    filter "configurations:Optimized"
        buildoptions "/MD"
    
    filter "configurations:Dist"
        buildoptions "/MD"