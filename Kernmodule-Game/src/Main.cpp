#include "KMCore/Core/Application.h"
#include "Levels/MainMenuLevel.h"

constexpr char*		     APP_TITLE = "Speed Racer";
constexpr float		     APP_WIDTH = WINDOW_WIDTH_REF;
constexpr float		    APP_HEIGHT = WINDOW_HEIGHT_REF;
constexpr unsigned int   APP_STYLE = sf::Style::Default;
constexpr bool APP_HAS_FRAME_LIMIT = true;
constexpr int	   APP_FRAME_LIMIT = 60;								

namespace KMGame
{
	class SpeedRacer : public Application
	{
	public:
		SpeedRacer()
			:Application(WindowData(APP_TITLE, sf::VideoMode(WINDOW_WIDTH_REF, WINDOW_HEIGHT_REF), APP_STYLE))
		{
			srand(static_cast<unsigned>(time(NULL)));
			AddLevel(new MainMenuLevel());
			GetWindow().SetVSync(true);
			
			auto window = GetWindow().GetRenderWindow();
			window->setMouseCursorVisible(false);

			if (APP_HAS_FRAME_LIMIT)
				window->setFramerateLimit(60);
		}
	};
}

int main()
{
	std::unique_ptr<KMGame::SpeedRacer> application = std::make_unique<KMGame::SpeedRacer>();
	application->GetWindow().GetRenderWindow()->setFramerateLimit(APP_FRAME_LIMIT);
	application->Run();
}