#pragma once
#include "KMCore/Core/Core.h"

namespace KMCore::Entity
{
	class Object
	{
	public:
		Object() = default;
		Object(const std::string& name)
			: m_Name(name){ }
		virtual ~Object() = default;
		
		virtual void OnStart() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnDestroy() {}

		bool enabled = true;

	private:
		std::string m_Name;
	};
}
