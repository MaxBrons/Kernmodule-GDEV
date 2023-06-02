#include "KMCore/Core/Application.h"
#include "SpeedRacerLevel.h"

class SpeedRacer : public Application
{
public:
	SpeedRacer()
		:Application(WindowData("Speed Racer", sf::VideoMode::getDesktopMode(), sf::Style::Fullscreen))
	{
		srand(static_cast<unsigned>(time(NULL)));
		AddLevel(new SpeedRacerLevel());
	}
};

int main()
{
	std::unique_ptr<SpeedRacer> application = std::make_unique<SpeedRacer>();
	application->GetWindow().GetRenderWindow()->setFramerateLimit(60);
	application->Run();
}