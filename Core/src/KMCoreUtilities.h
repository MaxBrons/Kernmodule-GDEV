#pragma once
#include "KMCore/Math/KMMathf.h"

using namespace KMCore::Mathf;

static float GetRandomValue(float maxValue)
{
	return  static_cast<float>(rand() & static_cast<int>(maxValue * 100.0f)) / 10.0f;
}