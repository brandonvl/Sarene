#include "sarpch.h"

#include "Application.h"

namespace Sarene
{
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application()
	{

	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
			{
				break;
			}
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
	}

	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();

			for (auto layer : m_LayerStack)
			{
				layer->OnUpdate();
			}
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
}

class ExampleLayer : public Sarene::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{

	}

	void OnUpdate() override
	{
		SAR_LOG_INFO("ExampleLayer::OnUpdate");
	}

	void OnEvent(Sarene::Event& event) override
	{
		SAR_LOG_TRACE("{0}", event);
	}
};

// Fine for now, rework later
int main()
{
	Sarene::Log::Init();
	SAR_LOG_INFO("Inialized logger!");

	Sarene::Application* app = new Sarene::Application();
	app->PushLayer(new ExampleLayer());
	app->Run();
	delete app;
}