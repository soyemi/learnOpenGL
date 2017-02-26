#pragma once
#include "AppBoxRender.h"

AppBase * app;
int main()
{
	app = new AppBoxRender("openGL test", 800, 600);
	app->Run();

	return 0;
}


