#include "sarpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Sarene
{
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		SAR_CORE_ASSERT(windowHandle, "Window handle is null!");
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		SAR_CORE_ASSERT(status, "Failed to initialize Glad!");

		SAR_CORE_INFO("OpenGL Info:");
		SAR_CORE_INFO(" Vendor: {0}", glGetString(GL_VENDOR));
		SAR_CORE_INFO(" Renderer: {0}", glGetString(GL_RENDERER));
		SAR_CORE_INFO(" Version: {0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}