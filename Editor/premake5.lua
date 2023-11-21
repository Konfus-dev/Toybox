project "Editor"
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
        "%{IncludeDir.Engine}"
    }

    links
    {
        "Engine"
    }

    -- Platforms
    filter "system:Windows"
        systemversion "Latest"
    
    -- Configurations
    filter "configurations:Debug"
        symbols "On"

    filter "configurations:Release"
        optimize "On"

    filter "configurations:Release"
        optimize "On"