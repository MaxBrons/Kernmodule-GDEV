#pragma once
#include "KMCore/Math/KMMathf.h"
#include <iostream>

using namespace KMCore::Math;

#ifdef _DEBUG
#define LOG(x) std::cout << x << std::endl
#else
#define LOG(x)
#endif

static float GetRandomValue(float maxValue)
{
	return  static_cast<float>(rand() & static_cast<int>(maxValue * 100.0f)) / 10.0f;
}