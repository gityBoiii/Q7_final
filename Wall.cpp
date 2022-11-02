#include "Wall.h"

AWall::AWall()
{
	Shape = '*';
	ZOrder = 20;
	CollisionType = ECollisionType::PhysicsOnly;
}

AWall::AWall(int NewX, int NewY)
	: AWall()
{
	X = NewX;
	Y = NewY;
}

AWall::~AWall()
{
}

