#pragma once

#include "Core.h"

#include "Window.h"
#include "Sarene/LayerStack.h"
#include "Events/Event.h"
#include "Sarene/Events/ApplicationEvent.h"

#include "Sarene/ImGui/ImGuiLayer.h"

#include "Sarene/Renderer/Shader.h"
#include "Sarene/Renderer/Buffer.h"
#include "Sarene/Renderer/VertexArray.h"

namespace Sarene
{
	class Application
	{
	public:
		Application();
		virtual ~Application() = default;

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline static Application& Get()
		{
			return *s_Instance;
		}

		inline Window& GetWindow()
		{
			return *m_Window;
		}
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		std::shared_ptr<Shader> m_Shader;
		std::shared_ptr<VertexArray> m_VertexArray;

		std::shared_ptr<Shader> m_BlueShader;
		std::shared_ptr<VertexArray> m_SquareVA;

		static Application* s_Instance;
	};

	// Define in Client
	Application* CreateApplication();
}