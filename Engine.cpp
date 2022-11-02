#include "Engine.h"
#include <conio.h>
#include "World.h"
#include <fstream>
#include "Player.h"
#include "Floor.h"
#include "Wall.h"
#include "Goal.h"
#include <algorithm>

using namespace std;

int Engine::KeyCode = 0;

Engine::Engine()
{
	MyWorld = new FWorld();
	bIsRunning = true;
}

Engine::~Engine()
{
	delete MyWorld;
}

void Engine::BeginPlay()
{
	MyWorld->BeginPlay();
}

void Engine::EndPlay()
{
	MyWorld->EndPlay();
}

void Engine::Run()
{
	BeginPlay();

	while (bIsRunning)
	{
		Input();
		Tick();
		Render();
	}

	EndPlay();
}

void Engine::QuitGame()
{
	bIsRunning = false;
}

void Engine::Load(string MapFilename)
{
	char Data[100];
	ifstream MapFile(MapFilename);

	int Y = 0;
	while (MapFile.getline(Data, 100))
	{
		for (int X = 0; X < strlen(Data); ++X)
		{
			if (Data[X] == '*')
			{
				MyWorld->SpawnActor(new AWall(X, Y));
				MyWorld->SpawnActor(new AFloor(X, Y));
			}
			else if (Data[X] == 'P')
			{
				MyWorld->SpawnActor(new APlayer(X, Y));
				MyWorld->SpawnActor(new AFloor(X, Y));
			}
			else if (Data[X] == 'G')
			{
				MyWorld->SpawnActor(new AGoal(X, Y));
				MyWorld->SpawnActor(new AFloor(X, Y));
			}
			else if (Data[X] == ' ')
			{
				MyWorld->SpawnActor(new AFloor(X, Y));
			}
		}
		Y++;
	}
	MapFile.close();

	//Sort
	SortActor();
}

void Engine::SortActor()
{
	sort(MyWorld->ActorList.begin(), MyWorld->ActorList.end(), AActor::Compare);
	//for (int i = 0; i < MyWorld->ActorList.size(); ++i)
	//{
	//	for (int j = i; j < MyWorld->ActorList.size(); ++j)
	//	{
	//		if (MyWorld->ActorList[i]->ZOrder > MyWorld->ActorList[j]->ZOrder)
	//		{
	//			AActor* Temp = MyWorld->ActorList[i];
	//			MyWorld->ActorList[i] = MyWorld->ActorList[j];
	//			MyWorld->ActorList[j] = Temp;
	//		}
	//	}
	//}
}

vector<AActor*>& Engine::GetAllActors()
{
	return MyWorld->ActorList;
}

void Engine::Input()
{
	Engine::KeyCode = _getch();
}

void Engine::Tick()
{
	MyWorld->Tick();
}

void Engine::Render()
{
	system("cls");

	MyWorld->Render();
}
