project "EditorCore"
    kind "SharedLib"
    language "C++"
    cppdialect "C++20"
    staticruntime "Off"

    entrypoint "mainCRTStartup"
    
    targetdir ("../../Build/bin/" .. outputdir .. "/%{prj.name}/")
    objdir    ("../../Build/obj/" .. outputdir .. "/%{prj.name}/")

    files
    {
        "./**.h",
        "./**.c",
        "./**.hpp",
        "./**.cpp",
    }

    includedirs
    {
        "%{IncludeDir.Engine}"
    }

    links
    {
        "Engine"
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
        runtime "Debug"
        optimize "On"
        symbols "On"
        defines
        {
            "TBX_DEBUG",
            "TBX_ASSERTS_ENABLED"
        }

    filter "configurations:Optimized"
        runtime "Release"
        optimize "On"
        symbols "On"
        defines
        {
            "TBX_OPTIMIZED"
        }
    
    filter "configurations:Dist"
        runtime "Release"
        optimize "On"
        symbols "Off"
        defines 
        {
            "TBX_RELEASE"
        }