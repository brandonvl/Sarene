#pragma once

#ifdef SAR_PLATFORM_WINDOWS

extern Sarene::Application* Sarene::CreateApplication();

int main(int argc, char** argv)
{
	Sarene::Log::Init();
	SAR_CORE_INFO("Initialized log!");

	auto app = Sarene::CreateApplication();
	app->Run();
	delete app;
}

#endif