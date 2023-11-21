project "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    staticruntime "Off"

    targetdir ("../Build/bin/" .. outputdir .. "/%{prj.name}")
    objdir    ("../Build/obj/" .. outputdir .. "/%{prj.name}")

    files
    {
        "./**.h",
        "./**.c",
        "./**.hpp",
        "./**.cpp"
    }

    includedirs
    {
        "%{IncludeDir.spdlog}",
        "%{IncludeDir.glfw}",
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
            "TBX_PLATFORM_WINDOWS"
        }
    
    -- Configurations
    filter "configurations:Debug"
        defines "TBX_DEBUG"
        symbols "On"

        defines
        {
            "TBX_ASSERTS_ENABLED"
        }

    filter "configurations:Release"
        defines "TBX_RELEASE"
        optimize "On"

    filter "configurations:Release"
        defines "TBX_DIST"
        optimize "On"