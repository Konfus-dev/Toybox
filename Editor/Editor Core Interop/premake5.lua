project "EditorCoreInterop"
    kind "SharedLib"
    language "C++"
    cppdialect "C++20"
    staticruntime "Off"

    targetdir ("../../" .. OutputDir .. "/bin/%{prj.name}/")
    objdir    ("../../" .. OutputDir .. "/obj/%{prj.name}/")

    files
    {
        "./**.h",
        "./**.c",
        "./**.hpp",
        "./**.cpp",
    }

	-- Editor Supported Platforms
	filter "system:Windows"
        defines
        {
			"TBX_EDITOR_CORE_EXPORT_DLL"
		}
	
	IncludeEngine()
	IncludeEditorCoreLib()
	StandardPlatformsAndConfigs()
	