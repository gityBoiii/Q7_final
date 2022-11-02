#pragma once

#ifndef __AACTOR_H__
#define __AACTOR_H__   

enum class ECollisionType
{
	NoCollision				=				0,  // 0000 0000
	QueryOnly				=				1,  // 0000 0001
	PhysicsOnly				=				2,  // 0000 0010
	CollisionEnable			=				(QueryOnly | PhysicsOnly),	// 0000 0011
};


class AActor
{
public:
	AActor();
	AActor(int NewX, int NewY);
	virtual ~AActor();

	virtual void Render();
	virtual void Tick();

	virtual void BeginPlay();
	virtual void EndPlay();

	int X;
	int Y;

	char Shape;

	int ZOrder;

	bool operator<(AActor& RHS)
	{
		return (this->ZOrder) < (RHS.ZOrder);
	}

	static inline bool Compare(AActor* First, AActor* Second)
	{
		return (First->ZOrder) < (Second->ZOrder);
	}

	bool CheckHit(AActor* Other);

	ECollisionType CollisionType = ECollisionType::NoCollision;
};


#endif


