project "Editor"
    language "C#"
    kind "WindowedApp"
    staticruntime "Off"
    csversion("12")
    
    targetdir ("../Build/bin/" .. outputdir .. "/%{prj.name}/")
    objdir    ("../Build/obj/" .. outputdir .. "/%{prj.name}/")

    files
    {
        "./**.cs",
        "./**.cpp",
        "./**.axaml",
        "./**.ico",
        "./**.jpg",
        "./**.png"
    }

    includedirs
    {
        "%{IncludeDir.Engine}"
    }

    links
    {
        "Engine",
        "Avalonia"
    }
        
    filter "files:**.cpp"
        buildaction "Compile"

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