#pragma once
#include "KMCore/Math/KMMathf.h"
#include <iostream>

using namespace KMCore::Math;

#ifdef _DEBUG
#define LOG(x) std::cout << x << std::endl
#else
#define LOG(x)
#endif

#define WINDOW_WIDTH_REF 1920.0f
#define WINDOW_HEIGHT_REF 1080.0f

static float GetRandomValue(float maxValue)
{
	return  static_cast<float>(rand() & static_cast<int>(maxValue * 100.0f)) / 100.0f;
}