#include "Player.h"
#include <iostream>
#include "MyEngine.h"

using namespace std;

APlayer::APlayer()
{
	Shape = 'P';
	ZOrder = 40;
	CollisionType = ECollisionType::CollisionEnable;
}

APlayer::APlayer(int NewX, int NewY)
	: APlayer()
{
	X = NewX;
	Y = NewY;
}

APlayer::~APlayer()
{
}

void APlayer::Tick()
{
	switch (Engine::GetKeyCode())
	{
		case 'W':
		case 'w':
			Y--;
			if (!PredictCanMove())
			{
				Y++;
			}
			
			break;

		case 'A':
		case 'a':
			X--;
			if (!PredictCanMove())
			{
				X++;
			}
			break;

		case 's':
		case 'S':
			Y++;
			if (!PredictCanMove())
			{
				Y--;
			}
			break;

		case 'd':
		case 'D':
			X++;
			if (!PredictCanMove())
			{
				X--;
			}
			break;

		case 'q':
		case 'Q':
			GEngine->QuitGame();

			break;
	}
}

bool APlayer::PredictCanMove()
{
	for (AActor* Actor : GEngine->GetAllActors())
	{
		if (X == Actor->X && Y == Actor->Y &&
			dynamic_cast<APlayer*>(Actor) == nullptr)
		{
			if (CheckHit(Actor))
			{
				return false;
			}
		}
	}

	return true;
}