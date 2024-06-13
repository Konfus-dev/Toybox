project "Sandbox"
    kind "WindowedApp"
    language "C++"
    cppdialect "C++20"
    staticruntime "Off"

    entrypoint "mainCRTStartup"
    
    targetdir ("../Build/bin/" .. outputdir .. "/%{prj.name}/")
    objdir    ("../Build/obj/" .. outputdir .. "/%{prj.name}/")

    files
    {
        "./**.h",
        "./**.c",
        "./**.hpp",
        "./**.cpp"
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
        defines "TBX_PLATFORM_WINDOWS"
    
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