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
			SAR_TRACE("Tab key is pressed (poll)!");
		}
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}
};

class Sandbox : public Sarene::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

Sarene::Application* Sarene::CreateApplication()
{
	return new Sandbox();
}