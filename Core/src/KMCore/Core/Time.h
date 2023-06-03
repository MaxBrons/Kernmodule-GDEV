#pragma once

namespace KMCore
{
	class Time
	{
	public:
		Time()
		{
			time = 0.0f;
			deltaTime = 0.0f;
		}

		static float time;
		static float deltaTime;
	};
}