project "Interop"
    kind "SharedLib"
    language "C++"
    cppdialect "C++20"
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

	-- Editor Supported Platforms
	filter "system:Windows"
        defines
        {
			"TBX_EDITOR_CORE_EXPORT_DLL"
		}
	
	IncludeEngine()
	StandardPlatformsAndConfigs()
	