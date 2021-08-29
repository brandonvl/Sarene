workspace "Sarene"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Sarene/vendor/glfw/include"

include "Sarene/vendor/glfw"

project "Sarene"
	location "Sarene"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


	pchheader "sarpch.h"
	pchsource "Sarene/src/sarpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%IncludeDir.GLFW"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"


	filter "configurations:Debug"
		defines "SAR_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SAR_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SAR_DIST"
		optimize "On"