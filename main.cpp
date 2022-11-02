#include <iostream>
#include <fstream>
#include "MyEngine.h"



int main()
{
	GEngine->Initialize();

	GEngine->Run();

	GEngine->Terminalize();

	delete GEngine;

	return 0;
}