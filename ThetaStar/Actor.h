#pragma once
#include "Includes.h"

class Actor
{
public:
	Actor(int GridPos,int DestPos);
	~Actor() {};

	int getGridPos() { return m_GridPos; };
	int getDestPos() { return m_DestPos; };

private:
	int m_GridPos;
	int m_DestPos;
};
