#include "sarpch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Sarene
{
	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}