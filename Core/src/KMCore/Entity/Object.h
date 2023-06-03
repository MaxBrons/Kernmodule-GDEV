#pragma once
#include "KMCore/Core/Core.h"

#define BASE(x) __super::x
namespace KMCore::Entity
{
	class Object
	{
	public:
		virtual ~Object() = default;
		
		virtual void OnStart() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnDestroy() = 0;

		bool enabled = true;
		std::string name;

	protected:
		Object(const std::string& name = "New Object")
			: m_Name(name)
		{
			this->name = m_Name;
		}

	protected:
		std::string m_Name;
	};
}
