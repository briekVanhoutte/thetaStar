#pragma once
#include "Grid.h"
#include "Actor.h"
class World
{
public:
	World(float width, float height, int rows, int columns);
	~World();
	void Draw();
	Grid* getGrid() { return m_Grid; };
	Actor* getActor() { return m_Actor; };
private:
	Grid* m_Grid = nullptr;
	Actor* m_Actor = nullptr;
};

