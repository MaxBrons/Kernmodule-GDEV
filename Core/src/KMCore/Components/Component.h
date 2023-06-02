#pragma once
#include <typeinfo>

namespace KMCore::Core
{
	class Component
	{
	public:
		Component() = default;
		virtual ~Component() = default;

		virtual void OnStart() {};
		virtual void OnUpdate() {};
		virtual void OnDestroy() {};

		bool operator==(const Component& other) const
		{
			return typeid(this) == typeid(other);
		}
	};
}
