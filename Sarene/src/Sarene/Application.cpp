#include "Application.h"
#include "Log.h"
#include "Events/ApplicationEvent.h"

namespace Sarene
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1200, 720);
		SAR_LOG_INFO(e);
		while (true);
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