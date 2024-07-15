project "Sandbox"
    kind "WindowedApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "Off"

    entrypoint "mainCRTStartup"
    
    targetdir ("../" .. OutputDir .. "/bin/%{prj.name}/")
    objdir    ("../" .. OutputDir .. "/obj/%{prj.name}/")

    files
    {
        "./**.h",
        "./**.c",
        "./**.hpp",
        "./**.cpp"
    }
	
	IncludeEngine()
    StandardPlatforms()
    StandardConfigs()