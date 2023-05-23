#include "Core/Application.h"
#include "SpeedRacerLevel.h"
class SpeedRacer : public Application
{
public:
	SpeedRacer()
		:Application({ "Speed Racer" })
	{
		AddLevel(new SpeedRacerLevel());
	}
};

int main()
{
	std::unique_ptr<SpeedRacer> application = std::make_unique<SpeedRacer>();
	application->Run();
}