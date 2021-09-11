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
        ~ImGuiLayer();

        void OnAttach();
        void OnDetach();
        void OnUpdate();
        void OnEvent(Event& event);

    private:
        float m_Time = 0.0f;

        bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
        bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
        bool OnMouseMovedEvent(MouseMovedEvent& e);
        bool OnMouseScrolledEvent(MouseScrolledEvent& e);
        bool OnKeyPressedEvent(KeyPressedEvent& e);
        bool OnKeyTypedEvent(KeyTypedEvent& e);
        bool OnKeyReleasedEvent(KeyReleasedEvent& e);
        bool OnWindowResizeEvent(WindowResizeEvent& e);
    };
}

