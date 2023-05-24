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

	private:
		std::string m_Name;
	};
}
