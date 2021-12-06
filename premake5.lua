workspace "Sarene"
	architecture "x64"
	startproject "Sandbox"

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
IncludeDir["Glad"] = "Sarene/vendor/glad/include"
IncludeDir["Imgui"] = "Sarene/vendor/imgui"
IncludeDir["glm"] = "Sarene/vendor/glm"
IncludeDir["stb_image"] = "Sarene/vendor/stb_image"

group "Dependencies"
	include "Sarene/vendor/glfw"
	include "Sarene/vendor/glad"
	include "Sarene/vendor/imgui"
group ""

project "Sarene"
		location "Sarene"
		kind "StaticLib"
		language "C++"
		cppdialect "C++17"
		staticruntime "on"

		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


		pchheader "sarpch.h"
		pchsource "Sarene/src/sarpch.cpp"

		files
		{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp",
			"%{prj.name}/vendor/stb_image/**.h",
			"%{prj.name}/vendor/stb_image/**.cpp",
			"%{prj.name}/vendor/glm/glm/**.hpp",
			"%{prj.name}/vendor/glm/glm/**.inl"
		}

		defines
		{
			"_CRT_SECURE_NO_WARNINGS"
		}

		includedirs
		{
			"%{prj.name}/src",
			"%{prj.name}/vendor/spdlog/include",
			"%{IncludeDir.GLFW}",
			"%{IncludeDir.Glad}",
			"%{IncludeDir.Imgui}",
			"%{IncludeDir.glm}",
			"%{IncludeDir.stb_image}"
		}

		links
		{
			"GLFW",
			"Glad",
			"Imgui",
			"opengl32.lib"
		}

		filter "system:windows"
			systemversion "latest"

			defines
			{
				"SAR_PLATFORM_WINDOWS",
				"GLFW_INCLUDE_NONE"
			}


		filter "configurations:Debug"
			defines "SAR_DEBUG"
			runtime "Debug"
			symbols "On"

		filter "configurations:Release"
			defines "SAR_RELEASE"
			runtime "Release"
			optimize "On"

		filter "configurations:Dist"
			defines "SAR_DIST"
			runtime "Release"
			optimize "On"

project "Sandbox"
		location "Sandbox"
		kind "ConsoleApp"
		language "C++"
		cppdialect "C++17"
		staticruntime "on"

		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

		files
		{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp"
		}

		includedirs
		{
			"Sarene/vendor/spdlog/include",
			"Sarene/src",
			"Sarene/vendor",
			"%{IncludeDir.glm}"
		}

		links
		{
			"Sarene"
		}

		filter "system:windows"
			systemversion "latest"

			defines
			{
				"SAR_PLATFORM_WINDOWS"
			}

		filter "configurations:Debug"
			defines "SAR_DEBUG"
			runtime "Debug"
			symbols "on"

		filter "configurations:Release"
			defines "SAR_RELEASE"
			runtime "Release"
			optimize "on"

		filter "configurations:Dist"
			defines "SAR_DIST"
			runtime "Release"
			optimize "on"

project "SCE"
		location "SCE"
		kind "ConsoleApp"
		language "C++"
		cppdialect "C++17"
		staticruntime "on"

		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

		files
		{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp"
		}

		includedirs
		{
			"Sarene/vendor/spdlog/include",
			"Sarene/src",
			"Sarene/vendor",
			"%{IncludeDir.glm}"
		}

		links
		{
			"Sarene"
		}

		filter "system:windows"
			systemversion "latest"

			defines
			{
				"SAR_PLATFORM_WINDOWS"
			}

		filter "configurations:Debug"
			defines "SAR_DEBUG"
			runtime "Debug"
			symbols "on"

		filter "configurations:Release"
			defines "SAR_RELEASE"
			runtime "Release"
			optimize "on"

		filter "configurations:Dist"
			defines "SAR_DIST"
			runtime "Release"
			optimize "on"
