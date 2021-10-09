#pragma once

#include "Core.h"

#include "Window.h"
#include "Sarene/LayerStack.h"
#include "Events/Event.h"
#include "Sarene/Events/ApplicationEvent.h"

#include "Sarene/ImGui/ImGuiLayer.h"

#include "Sarene/Renderer/Shader.h"
#include "Sarene/Renderer/Buffer.h"

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

		unsigned int m_VertexArray;
		std::unique_ptr<Shader> m_Shader;
		std::unique_ptr<VertexBuffer> m_VertexBuffer;
		std::unique_ptr<IndexBuffer> m_IndexBuffer;

		static Application* s_Instance;
	};

	// Define in Client
	Application* CreateApplication();
}