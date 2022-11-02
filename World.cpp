#include "World.h"
#include "Actor.h"
#include <algorithm>

FWorld::FWorld()
{
}

FWorld::~FWorld()
{
	for (auto Value : ActorList)
	{
		if (Value)
		{
			delete Value;
		}
	}

	ActorList.clear();
}


void FWorld::SpawnActor(AActor* NewActor)
{
	if (NewActor)
	{
		ActorList.push_back(NewActor);
	}
}

void FWorld::DestroyActor(AActor* DeleteActor)
{
	//STL
	if (DeleteActor)
	{
		ActorList.erase(find(ActorList.begin(), ActorList.end(), DeleteActor));

		delete DeleteActor;
	}

	//for (auto iter = ActorList.begin(); iter != ActorList.end(); ++iter)
	//{
	//	if (*iter == DeleteActor)
	//	{
	//		ActorList.erase(iter);
	//		break;
	//	}
	//}
}

void FWorld::Render()
{
	for (auto Value : ActorList)
	{
		Value->Render();
	}
}

void FWorld::Tick()
{
	for (auto Value : ActorList)
	{
		Value->Tick();
	}
}

void FWorld::BeginPlay()
{
	//World BeginPlay

	for (auto Value : ActorList)
	{
		Value->BeginPlay();
	}
}

void FWorld::EndPlay()
{
	for (auto Value : ActorList)
	{
		Value->EndPlay();;
	}

	//World EndPlay
}

