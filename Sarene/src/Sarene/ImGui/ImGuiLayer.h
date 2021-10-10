#pragma once

#include "Sarene/Layer.h"
#include "Sarene/Events/ApplicationEvent.h"
#include "Sarene/Events/KeyEvent.h"
#include "Sarene/Events/MouseEvent.h"

namespace Sarene
{
	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();

	private:
		float m_Time = 0.0f;
	};
}

