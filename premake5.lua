workspace "photoeditor"
    startproject "photoeditor"
    architecture "ARM64"
    configurations { "Debug", "Release" }

-- Binary and Object Directories --
tdir = "bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}/"
odir = "bin-int/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}/"

-- External Dependencies --
dependencies = {}
dependencies["spdlog"] = "photoengine/deps/spdlog"
dependencies["glfw"] = "photoengine/deps/glfw"
dependencies["glad"] = "photoengine/deps/glad"
dependencies["imgui"] = "photoengine/deps/imgui"

include "photoengine/deps/glad"
include "photoengine/deps/imgui"

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
        "%{dependencies.imgui}/backends/imgui_impl_opengl3.cpp",
        "%{dependencies.imgui}/backends/imgui_impl_glfw.cpp",
    }

    includedirs
    {
        "%{prj.name}/include",
        "%{dependencies.spdlog}/include",
        "%{dependencies.glfw}/include",
        "%{dependencies.glad}/include",
        "%{dependencies.imgui}"
    }

    defines "GLFW_INCLUDE_NONE"

    filter { "system:macosx" }

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
    targetname "PhotoEditor"
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
        "%{prj.name}/include",
        "%{dependencies.spdlog}/include"
    }

    links 
    {
        "photoengine",
        "glfw3",
        "glad",
        "imgui"
    }

    filter { "system:macosx" }
        links { "Cocoa.framework", "OpenGL.framework", "IOKit.framework" }
        libdirs "%{dependencies.glfw}/lib-arm64"    -- Add support for x64

    filter { "system:windows" }
        systemversion "latest"

    filter { "configurations:Debug" }
        runtime "Debug"
        symbols "on"

    filter { "configurations:Release" }
        runtime "Release"
        optimize "on"
