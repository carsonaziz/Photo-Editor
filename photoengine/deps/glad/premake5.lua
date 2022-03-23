project "glad"
    kind "StaticLib"
    language "C"
    staticruntime "on"
    configurations { "Debug", "Release" }

    targetdir(tdir)
    objdir(odir)

    files
    {
        "include/**.h",
        "src/glad.c"
    }

    includedirs
    {
        "include"
    }

    filter "system:windows"
        systemversion "latest"

    filter "configurations:Debug"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        runtime "Release"
        optimize "on"
