
workspace "DesignPatterns"
    architecture "x64"
    configurations { "Debug", "Release" }
    location "build"
    toolset "clang"

project "Observer"
    location "build"
    kind "ConsoleApp"
    language "C++"
    targetdir "bin/%{cfg.buildcfg}"
    cppdialect "C++17"

    files {"**.hpp", "src/**.cpp"}
    includedirs 
    {
        "%{prj.name}/**.hpp",
        "%{prj.name}/**.cpp"
    }

    filter "configurations:Debug"
        defines {"DEBUG"}
        symbols "On"

    filter "configurations:Release"
        defines {"NDEBUG"}
        optimize "On"


        
