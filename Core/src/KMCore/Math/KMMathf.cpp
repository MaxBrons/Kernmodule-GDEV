#include "kmpch.h"
#include "KMMathf.h"

namespace KMCore::Mathf
{
	float KMMathf::abs(float value)
	{
		return value >= 0 ? value : value * -1;
	}

	float KMMathf::min(float a, float b)
	{
		return (a < b) ? a : b;
	}

	float KMMathf::max(float a, float b)
	{
		return (a > b) ? a : b;
	}

	float KMMathf::clamp(float value, float min, float max)
	{
		if (value < min)
		{
			value = min;
		}
		else if (value > max)
		{
			value = max;
		}

		return value;
	}
}
