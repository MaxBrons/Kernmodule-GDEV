#pragma once
#include <typeinfo>

namespace KMCore::Core
{
	class Component
	{
	public:
		virtual ~Component() = default;

		virtual void OnStart() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnDestroy() = 0;
	};
}
