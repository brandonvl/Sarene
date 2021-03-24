#include "Application.h"
#include "Log.h"

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