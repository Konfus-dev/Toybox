project "EditorCore"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    staticruntime "Off"

    targetdir ("../../" .. OutputDir .. "/bin/%{prj.name}/")
    objdir    ("../../" .. OutputDir .. "/obj/%{prj.name}/")

    files
    {
        "../Editor Core Lib/**.h",
        "../Editor Core Lib/**.c",
        "../Editor Core Lib/**.hpp",
        "../Editor Core Lib/**.cpp",
    }

	IncludeEngine()
	IncludeEditorCoreLib()
	StandardPlatformsAndConfigs()