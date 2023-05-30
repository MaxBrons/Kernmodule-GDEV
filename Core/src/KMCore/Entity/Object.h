#pragma once
#include "KMCore/Core/Core.h"

#define BASE(x) __super::x
namespace KMCore::Entity
{
	class Object
	{
	public:
		Object() = default;
		Object(const std::string& name = "New Object")
			: m_Name(name){ }
		virtual ~Object() = default;
		
		virtual void OnStart() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnDestroy() {}

		bool enabled = true;

	protected:
		std::string m_Name;
	};
}
