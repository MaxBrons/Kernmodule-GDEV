#pragma once

namespace KMCore::Math
{
	static class KMMathf
	{
	public:
		static float abs(float value);
		static float min(float a, float b);
		static float max(float a, float b);
		static float clamp(float value, float min, float max);
	};
}
