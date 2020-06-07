// HybridEngine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SystemClass.h"

int main()
{
	SystemClass *sys;
	bool res;

	sys = new SystemClass();
	if (!sys) {
		return 1;
	}

	if (sys->initialize()) {
		sys->run();;
	}

	sys->shutdown();
	delete sys;

	return 0;
}
