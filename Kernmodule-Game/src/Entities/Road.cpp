#include "kmpch.h"
#include "Road.h"

namespace KMGame::Entity
{
	Road::Road(const Core::Transform& transform, const std::string& name)
		:GameObject(transform, name)
	{
		m_Window = static_cast<KMCore::GameWindow*>(&Application::Get().GetWindow());

		m_Backgrounds = std::vector<Sprite*>({
			new Sprite("assets/Sprites/background-1.png"),
			new Sprite("assets/Sprites/background-1.png"),
			new Sprite("assets/Sprites/background-1.png")
			});
	}

	void Road::OnStart()
	{
		BASE(OnStart());

		for (int i = 0; i < m_Backgrounds.size(); i++)
		{
			int inverseCount = ((int)m_Backgrounds.size() - (i + 1));
			m_Backgrounds[i]->transform->SetSize(WINDOW_WIDTH_REF, WINDOW_HEIGHT_REF);
			m_Backgrounds[i]->transform->SetPosition(0.0f, -(m_Backgrounds[i]->transform->GetSize().y * inverseCount) + (50.0f * KMMathf::min(inverseCount, 1)));
			m_Backgrounds[i]->OnStart();
		}
	};

	void Road::OnUpdate()
	{
		BASE(OnUpdate());

		for (auto* bg : m_Backgrounds)
		{
			bg->OnUpdate();

			if (bg->transform->GetPosition().y > m_Window->GetHeight())
				bg->transform->Move(0.0f, -(bg->transform->GetSize().y * 2));

			bg->transform->Move(0.0f, m_Speed.y);
		}
	}

	void Road::OnDestroy()
	{
		BASE(OnDestroy());

		for (auto& bg : m_Backgrounds)
		{
			bg->OnDestroy();
			delete bg;
		}
		m_Backgrounds.clear();
	}

	void Road::OnDraw()
	{
		for (auto* bg : m_Backgrounds)
			bg->Draw(m_Window);
	}
}
