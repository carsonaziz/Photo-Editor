workspace "photoeditor"
    startproject "photoeditor"
    architecture "ARM64"
    configurations { "Debug", "Release" }

-- Binary and Object Directories
tdir = "bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}/"
odir = "bin-int/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}/"

project "photoengine"
    location "photoengine"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir(tdir)
    objdir(odir)

    files
    {
        "%{prj.name}/include/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "%{prj.name}/include"
    }

    filter { "system:macosx" }
        links { "glfw3", "Cocoa.framework", "OpenGL.framework", "IOKit.framework" }

    filter { "system:windows" }
        systemversion "latest"

    filter { "configurations:Debug" }
        runtime "Debug"
        symbols "on"

    filter { "configurations:Release" }
        runtime "Release"
        optimize "on"

project "photoeditor"
    location "photoeditor"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir(tdir)
    objdir(odir)

    files
    {
        "%{prj.name}/include/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "photoengine/include",
        "%{prj.name}/include"
    }

    links "photoengine"

    filter { "system:macosx" }

    filter { "system:windows" }
        systemversion "latest"

    filter { "configurations:Debug" }
        runtime "Debug"
        symbols "on"

    filter { "configurations:Release" }
        runtime "Release"
        optimize "on"
