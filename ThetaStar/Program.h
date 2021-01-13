#pragma once

#include "World.h"
#include "Solver.h"

class Program
{
public:
	Program();
	~Program();

	void Draw();

	void Update(float elapsedSeconds);

	const int getWidth() { return m_Width; };
	const int getHeight() { return m_Height; };

private:
	const int m_Width{ 1920 };
	const int m_Height{ 1080 };
	Solver* m_Solver{};

	int m_AmountOfNodes{100};
	int m_AmountOfActors{99};//cannot be higher then nodes-1
	int m_AmountOfConnectionsPerNode{4};//cannot be uneven and cannot exeed sqrt amountOfNodes
	float m_SquareSize{30.f};
	World* m_World{};
	
};
