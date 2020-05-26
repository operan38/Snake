#include "App.h"

int main(int argc, char* args[])
{
	App app;
	if (app.Init())
		app.Loop();

	return 0;
}