#pragma once

#include <random>
#include "Application.h"
#include "Core.h"

class _API Math
{
public:
	static glm::vec3 ScreenToWorldPoint(const glm::vec3& pos, const glm::mat4& eye);

	static float RandomFloat(float range1, float range2);

	static int RandomInt(int range1, int range2);

	static float Time();
};
