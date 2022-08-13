﻿#pragma once

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

enum class RendererAPI
{
	None = 0, OpenGL = 1
};


class Renderer
{
	static RendererAPI s_RendererAPI;
public:
	inline static RendererAPI GetAPI() { return s_RendererAPI; }
public:
	static void Init();
	static void Shutdown();

	//Primitives
	static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color);
	static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color);


	static void DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float rotation, const glm::vec4& color);
	static void DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float rotation, const glm::vec4& color);

	static void DrawCircle(const glm::mat4& transform, const glm::vec4& color, float thickness = 1.0f, float fade = 0.005f);

	static void DrawLine(const glm::vec3& p0, glm::vec3 p1, const glm::vec4& color);

	static void DrawRect(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color);
	static void DrawRect(const glm::mat4& transform, const glm::vec4& color);
};
