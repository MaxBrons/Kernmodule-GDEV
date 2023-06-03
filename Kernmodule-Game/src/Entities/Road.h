#pragma once
#include "KMCore/Entity/Sprite.h"
#include "KMCore/Components/ColliderComponent.h"
#include "KMCore/Components/RigidBodyComponent.h"

using namespace KMCore;
using namespace KMCore::Entity;

namespace KMGame::Entity
{
	class Road : public GameObject
	{
	public:
		Road(const Core::Transform& transform = Core::Transform(), const std::string& name = "Background");
		~Road() = default;

		void OnStart() override;
		void OnUpdate() override;
		void OnDestroy() override;

	protected:
		void OnDraw() override;

	private:
		KMCore::GameWindow* m_Window = nullptr;
		std::vector<Sprite*> m_Backgrounds;
	};
}
