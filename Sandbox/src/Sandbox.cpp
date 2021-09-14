#include "Sarene.h"

#include "imgui/imgui.h"

class ExampleLayer : public Sarene::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		if (Sarene::Input::IsKeyPressed(SAR_KEY_TAB))
		{
			SAR_LOG_TRACE("Tab key is pressed (poll)!");
		}
	}
};

class Sandbox : public Sarene::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Sarene::ImGuiLayer());
	}

	~Sandbox()
	{

	}
};

Sarene::Application* Sarene::CreateApplication()
{
	return new Sandbox();
}