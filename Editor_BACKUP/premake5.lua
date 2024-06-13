project "Editor"
    language "C#"
    kind "WindowedApp"
    staticruntime "Off"
    csversion("12")
    
    targetdir ("../../Build/bin/" .. outputdir .. "/%{prj.name}/")
    objdir    ("../../Build/obj/" .. outputdir .. "/%{prj.name}/")

    files
    {
        "./**.cs",
		"Assets\**"
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
		-- Build props
        AccelerateBuildsInVisualStudio = "true",
        AppendTargetFrameworkToOutputPath = "false",
        Nullable = "enable",
		OutputType = "WinExe",
		TargetFramework = "8.0",
		BuiltInComInteropSupport = "true",
		ApplicationManifest = "app.manifest",
        AvaloniaUseCompiledBindingsByDefault = "true",
		
		-- Package ref props
		
        PackageReference = "Avalonia",
        PackageReference Include="Avalonia.Desktop" Version="11.0.10"/>
        PackageReference Include="Avalonia.Themes.Fluent" Version="11.0.10"/>
        PackageReference Include="Avalonia.Fonts.Inter" Version="11.0.10"/>
    }

	<!--Build-->
    <PropertyGroup>
        <OutputType>WinExe</OutputType>
        <TargetFramework>net8.0</TargetFramework>
        <Nullable>enable</Nullable>
        <BuiltInComInteropSupport>true</BuiltInComInteropSupport>
        <ApplicationManifest>app.manifest</ApplicationManifest>
        <AvaloniaUseCompiledBindingsByDefault>true</AvaloniaUseCompiledBindingsByDefault>
    </PropertyGroup>

    <!--Resources-->
    <ItemGroup>
        <Folder Include="Models\"/>
        <AvaloniaResource Include="Assets\**"/>
    </ItemGroup>

    <!--Packages-->
    <ItemGroup>
        <!--Condition below is needed to remove Avalonia.Diagnostics package from build output in Release configuration.-->
        <PackageReference Condition="'$(Configuration)' == 'Debug'" Include="Avalonia.Diagnostics" Version="11.0.10"/>
        <PackageReference Include="Avalonia.ReactiveUI" Version="11.0.10"/>
    </ItemGroup>

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

    filter "configurations:Release"
        optimize "On"
        defines "TBX_DIST"