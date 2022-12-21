project "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "off"

    targetdir ("../Build/bin/" .. outputdir .. "/%{prj.name}")
    objdir    ("../Build/obj/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/**.h",
        "%{prj.name}/**.c",
        "%{prj.name}/**.hpp",
        "%{prj.name}/**.cpp"
    }

    includedirs
    {
        "%{IncludeDir.spdlog}",
        "%{IncludeDir.glfw}",
        "%{IncludeDir.bgfx}",
        "Engine"
    }

    links
    {
        "Engine"
    }

    -- Platforms
    filter "system:windows"
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