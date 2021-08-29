#include "sarpch.h"

#include "Application.h"

namespace Sarene
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}
}


// Fine for now, rework later
int main()
{
	Sarene::Log::Init();
	SAR_LOG_INFO("Inialized logger!");

	Sarene::Application *app = new Sarene::Application();
	app->Run();
	delete app;
}