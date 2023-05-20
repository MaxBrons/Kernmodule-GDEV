#include "Core.h"
#include "Core/Application.h"

int main()
{
	std::unique_ptr<KMCore::Application> application = std::make_unique<KMCore::Application>(KMCore::WindowData());
	application->Run();
	return 0;
}