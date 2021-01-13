#include "World.h"
#include <algorithm>

World::World(float width, float height, int rows, int columns)
{
	int actorPos{ 5 * rows + 5 };
	int destPos{ 6 * rows + 3 };

	int randActorPos{ (rand() % columns) * rows + rand() % rows };
	int randDestPos{ (rand() % columns) * rows + rand() % rows };

	int amountOfWalls{ 100 };


	actorPos = randActorPos;
	destPos = randDestPos;
	while (destPos == actorPos)
	{
		randDestPos = (rand() % columns) * rows + rand() % rows ;
		destPos = randDestPos;
	}

	m_Grid = new Grid{ width,height,rows, columns,amountOfWalls };
	m_Actor = new Actor{ actorPos,destPos };

	m_Grid->setSquareState(actorPos, TileState::actor);
	m_Grid->setSquareState(destPos, TileState::goal);
}

World::~World()
{
	if (m_Grid)
	{
		delete m_Grid;
	}
	if (m_Actor)
	{
		delete m_Actor;
	}
}
void World::Draw()
{
	m_Grid->Draw();
}
