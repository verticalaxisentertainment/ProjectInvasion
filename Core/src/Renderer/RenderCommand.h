#pragma once

#include "Renderer/RendererAPI.h"

class RenderCommand
{
public:
	static void Init()
	{
		s_RendererAPI->Init();
	}

	static void SetViewPort(uint32_t x,uint32_t y,uint32_t width,uint32_t height)
	{
		s_RendererAPI->SetViewport(x, y, width, height);
	}

	static void SetClearColor(const glm::vec4& color)
	{
		s_RendererAPI->SetClearColor(color);
	}

	static void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray, uint32_t indexCount = 0)
	{
		s_RendererAPI->DrawIndexed(vertexArray, indexCount);
	}

	static void DrawLines(const std::shared_ptr<VertexArray>& vertexArray)
	{
		s_RendererAPI->DrawLines(vertexArray, 2);
	}

	static void SetLineWidth(float width)
	{
		s_RendererAPI->SetLineWidth(width);
	}
private:
	static std::unique_ptr<RendererAPI> s_RendererAPI;
};
