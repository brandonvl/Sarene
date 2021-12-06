#include "Sarene.h"
#include "EditorLayer.h"

class SCEApp : public Sarene::Application
{
public:
	SCEApp()
	{
		PushLayer(new SCE::EditorLayer());
	}

	~SCEApp()
	{

	}
};

Sarene::Application* Sarene::CreateApplication()
{
	return new SCEApp();
}