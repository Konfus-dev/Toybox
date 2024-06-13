project "Editor"
    language "C#"
    kind "WindowedApp"
    staticruntime "Off"
    
    targetdir ("../../Build/bin/" .. outputdir .. "/%{prj.name}/")
    objdir    ("../../Build/obj/" .. outputdir .. "/%{prj.name}/")

    files
    {
        "./**.cs"
    }

    includedirs
    {
        "Assets"
    }

    links
    {
        "EditorCore",
        "System",
        "System.Core",
        "System.Runtime.Serialization",
        "System.ComponentModel.DataAnnotations",
        "Microsoft.CSharp",
        "Avalonia",
        "Avalonia.Desktop",
        "Avalonia.Themes.Fluent",
        "Avalonia.Fonts.Inter",
        "Avalonia.ReactiveUI"
    }

    nuget
    {
        "Avalonia:11.0.10",
        "Avalonia.Desktop:11.0.10",
        "Avalonia.Themes.Fluent:11.0.10",
        "Avalonia.Fonts.Inter:11.0.10",
        "Avalonia.Diagnostics:11.0.10",
        "Avalonia.ReactiveUI:11.0.10"
    }
	
	vsprops
	{
        AccelerateBuildsInVisualStudio = "true",
        AppendTargetFrameworkToOutputPath = "false",
        Nullable = "enable",
		OutputType = "WinExe",
		TargetFramework = "8.0",
		BuiltInComInteropSupport = "true",
		ApplicationManifest = "app.manifest",
        AvaloniaUseCompiledBindingsByDefault = "true",
    }

    -- Platforms
    filter "system:Windows"
        systemversion "latest"
        defines
        { 
            "TOYBOX",
            "TOYBOX_EXPORT_DLL", 
            "TBX_PLATFORM_WINDOWS"
        }
    
    -- Configurations
    filter "configurations:Debug"
        symbols "On"
		links { "Avalonia.Diagnostics" }
        defines
        {
            "TBX_DEBUG",
            "TBX_ASSERTS_ENABLED"
        }

    filter "configurations:Release"
        optimize "On"
        defines "TBX_RELEASE"