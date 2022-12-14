#pragma once

#include "Layer/LayerStack.h"
#include "Layer/ImGUILayer.h"
#include "Window.h"
#include "Events/ApplicationEvent.h"
#include "Events/MouseEvent.h"

#include "Renderer/Shader.h"
#include "Renderer/Buffer.h"
#include "Renderer/VertexArray.h"
#include "Renderer/Texture.h"
#include "Renderer/OrthographicCameraController.h"
#include "Core.h"

#define BIND_EVENT_FN(x) std::bind(&x,this,std::placeholders::_1)

class ExampleLayer:public Layer
{
public:
	ExampleLayer()
		:Layer("ExampleLayer"){}

	void OnUpdate() override
	{
		//std::cout << "ExampleLayer::Update\n";
	}

	void OnEvent(Event& e) override
	{
		//std::cout << e << "\n";
	}
};


class _API Application
{
public:
	Application();
	~Application();
	void Run();

	void OnEvent(Event& e);

	void PushLayer(Layer* layer);
	void PushOverlay(Layer* overlay);

	inline static Application& Get() { return *s_Instance; }
	inline Window& GetWindow() const{ return *m_Window; }

	bool showPostProcessing = false;
	ImGUILayer* m_ImGuiLayer;
private:
	bool OnWindowClose(WindowCloseEvent& e);
	LayerStack m_LayerStack;


	std::unique_ptr<Window> m_Window;
	inline static bool m_Running = true;

	std::shared_ptr<Shader> m_ScreenShader;
	std::shared_ptr<FrameBuffer> m_FrameBuffer;
	
	static Application* s_Instance;
};

Application* CreateApplication();//defined client side
