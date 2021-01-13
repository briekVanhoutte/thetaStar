#include "Solver.h"
#include <map>
#include <set>
#include <iostream>
#include <algorithm>

Solver::Solver()
{
}

Solver::~Solver()
{
	for (Square* s : m_Path)
	{
		if (s)
		{
			delete s;
			s = nullptr;
		}
	}
	m_Path.clear();
}



std::vector<int> Solver::SolveThetaStar(Actor* actor, Grid* grid)
{
	bool end{};
	float gScore = 0;
	m_StartPos = actor->getGridPos();
	m_EndPos = actor->getDestPos();

	setDistances(grid);
	grid->getGridSpot(m_StartPos)->setParent(grid->getGridSpot(m_StartPos));


	m_Open.push_back(grid->getGridSpot(m_StartPos));

	grid->getGridSpot(actor->getGridPos())->setG(0 + Calcheuristic(m_StartPos, m_EndPos, grid));
	while (m_Open.size() != 0 && !end)
	{
		Square* s{ PopBack(m_Open) };
		m_Path.push_back(s);
		if (s == grid->getGridSpot(m_EndPos))
		{
			reconstructPath(s);
			end = true;
		}
		if (!end)
		{
			m_Closed.push_back(s);
			for (Square* neighbor : s->getNeighbors())
			{
				
				if (std::find(m_Closed.begin(), m_Closed.end(), neighbor) == m_Closed.end())
				{
					if (std::find(m_Open.begin(), m_Open.end(), neighbor) == m_Open.end())
					{
						m_Open.push_back(neighbor);
						neighbor->makeParentEmpty();
					}

					update_vertex(s, neighbor, grid);
				}
			}
		}
		sortOpen();
		
	}
	std::vector<int> pathid{};
	for (Square* s : m_Path)
	{
		pathid.push_back(s->getId());
	}
	for (Square* s : m_Open)
	{
		s->setState(TileState::checked);
	}
	pathid.erase(std::find(pathid.begin(), pathid.end(), pathid[pathid.size() - 1]));
	return pathid;
}

float Solver::CalcgScore(int pos, int startPos, Grid* grid)
{
	return grid->getDistanceFromTo(pos, startPos);
}
float Solver::Calcheuristic(int pos, int endPos, Grid* grid)
{
	return grid->getDistanceFromTo(pos, endPos);
}

Square* Solver::PopBack(std::vector<Square*>& vector)
{
	Square* result{};
	if (vector.size() - 1 >= 0)
	{
		result = vector[vector.size() - 1];
		vector.erase(vector.end() - 1);
	}
	else
	{
		std::cout << "vector was empty\n";
	}
	return result;
}

Square* Solver::reconstructPath(Square* s)
{
	Square* curS = s;
	while (curS->getParent() != nullptr)
	{
		m_Path.push_back(curS);
		curS = curS->getParent();
	}
	return nullptr;
}

void Solver::update_vertex(Square* s, Square* neighbor, Grid* grid)
{
	if (line_of_sight(s->getParent(), neighbor))
	{
		if (s->getParent()->getG() < neighbor->getG())
		{
			neighbor->setParent(s->getParent());
			auto it = std::find(m_Open.begin(), m_Open.end(), neighbor);
			if (it != m_Open.end())
			{
				m_Open.erase(it);
			}

			m_Open.push_back(neighbor);
		}
	}
	else
	{
		if (s->getG() < neighbor->getG())
		{
			neighbor->setParent(s);
			auto it = std::find(m_Open.begin(), m_Open.end(), neighbor);
			if (it != m_Open.end())
			{
				m_Open.erase(it);
			}
			m_Open.push_back(neighbor);
		}
	}
}

bool Solver::line_of_sight(Square* s, Square* neighbor)
{
	if (s != nullptr)
	{
		for (Square* direction : s->getNeighbors())
		{
			int directionInt{};
			if (s->getLeft() == direction)
			{
				directionInt = 0;
			}
			if (s->getRight() == direction)
			{
				directionInt = 1;
			}
			if (s->getTop() == direction)
			{
				directionInt = 2;
			}
			if (s->getBot() == direction)
			{
				directionInt = 3;
			}
			Square* curSquare = direction;
			while (curSquare != nullptr)
			{
				if (curSquare == neighbor)
				{
					return true;
				}
				else
				{
					if (directionInt == 0)
					{
						curSquare = curSquare->getLeft();
					}
					if (directionInt == 1)
					{
						curSquare = curSquare->getRight();
					}
					if (directionInt == 2)
					{
						curSquare = curSquare->getTop();
					}
					if (directionInt == 3)
					{
						curSquare = curSquare->getBot();
					}
					else
					{
						curSquare = nullptr;
					}
				}
			}
		}

	}


	return false;
}

void Solver::setDistances(Grid* grid)
{
	for (Square* s : grid->getSquares())
	{
		s->setG(CalcgScore(s->getId(),m_EndPos,grid));
	}
}

void Solver::sortOpen()
{
	Square* final{};
	for (Square* s : m_Open)
	{
		if (final == nullptr)
		{
			final = s;
		}
		else
		{
			if (final->getG() > s->getG())
			{
				final = s;
			}
		}
	}
	if (m_Open.size() > 0)
	{
		m_Open[m_Open.size() - 1] = final;
	}
	
}