#pragma once
#include "Actor.h"


class APlayer : public AActor
{
public:
	APlayer();
	APlayer(int NewX, int NewY);

	~APlayer();

	virtual void Tick() override;
	bool PredictCanMove();
};

