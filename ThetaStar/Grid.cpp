#include "Grid.h"
#include <math.h>
Grid::Grid(float width, float height, int rows, int columns, int amountWalls)
	: m_Width{ width }
	, m_Height{ height }
	, m_Rows{ rows }
	, m_Columns{ columns }
	, m_AmountWalls{amountWalls}
{
	
	SetupgRid();
}

Grid::~Grid()
{
	for (Square* s : m_Squares)
	{
		if (s != nullptr)
		{
			delete s;
			s = nullptr;
		}
	}
	m_Squares.clear();
}

void Grid::Draw()
{
	for (Square* square : m_Squares)
	{
		square->Draw();
	}
}

void Grid::SetupgRid()
{
	float gridWidth{ m_Width / m_Rows };
	float gridHeight{ m_Height / m_Columns };

	int id{};
	for (int col{}; col < m_Columns; col++)
	{
		for (int row{}; row < m_Rows; row++)
		{
			Square* s = new Square{ Float2{gridWidth * row,gridHeight * col},gridWidth,gridHeight };
			s->setState(TileState::notChecked);
			s->setId(id);
			m_Squares.push_back(s);
			id++;
		}
	}

	GenerateWalls(m_AmountWalls,m_Rows,m_Columns);

	for (int col{}; col < m_Columns; col++)
	{
		for (int row{}; row < m_Rows; row++)
		{
			int pos{ m_Rows * col + row };

			if (col != 0)
			{
				if (!(m_Squares[pos - m_Rows]->IsWall()))
				{	
					if (!m_Squares[pos]->IsWall())
					{
						m_Squares[pos]->addNeighbor(m_Squares[pos - m_Rows]);
						m_Squares[pos]->setTop(m_Squares[pos - m_Rows]);
					}
					
				}
			}
			if (col != m_Columns - 1)
			{
				if (!(m_Squares[pos + m_Rows]->IsWall()))
				{
					m_Squares[pos]->addNeighbor(m_Squares[pos + m_Rows]);
					m_Squares[pos]->setBot(m_Squares[pos + m_Rows]);
				}
			}
			if (row != 0)
			{
				if (!(m_Squares[pos - 1]->IsWall()))
				{
					m_Squares[pos]->addNeighbor(m_Squares[pos - 1]);
					m_Squares[pos]->setLeft(m_Squares[pos - 1]);
				}
			}
			if (row != m_Rows - 1)
			{
				if (!(m_Squares[pos + 1]->IsWall()))
				{
					m_Squares[pos]->addNeighbor(m_Squares[pos + 1]);
					m_Squares[pos]->setRight(m_Squares[pos + 1]);
				}
			}
		}
	}
}

void Grid::setSquareState(unsigned int pos, TileState state)
{
	if (pos < m_Squares.size())
	{
		m_Squares[pos]->setState(state);
	}
}

float Grid::getDistanceFromTo(int start, int end)
{
	Float2 startPos{ m_Squares[start]->getPositionMiddle() };
	Float2 EndPos{ m_Squares[end]->getPositionMiddle() };

	return sqrtf(((EndPos.x - startPos.x) * (EndPos.x - startPos.x)) + ((EndPos.y - startPos.y) * (EndPos.y - startPos.y)));
}

std::vector<Square*> Grid::getNeighborFromPos(unsigned int pos)
{
	return m_Squares[pos]->getNeighbors();
}

void Grid::GenerateWalls(int amount, int row, int col)
{
	for (int idx{}; idx < amount; idx++)
	{
		int testCounter{};
		int testWall{};
		while (!checkValidWall(testWall, row))
		{
			testWall = (rand() % col) * row + rand() % row;
			testCounter++;
			if (testCounter > row * col)
			{
				return;
			}
		}
		m_Squares[testWall]->setState(TileState::wall);
		m_Walls.push_back(testWall);
	}
}

bool Grid::checkValidWall(int wall, int row)
{
	auto it = std::find(m_Walls.begin(), m_Walls.end(), wall);
	if (it != m_Walls.end())
	{
		return false;
	}
	it = std::find(m_Walls.begin(), m_Walls.end(), wall + 1);
	if (it != m_Walls.end())
	{
		return false;
	}
	it = std::find(m_Walls.begin(), m_Walls.end(), wall - 1);
	if (it != m_Walls.end())
	{
		return false;
	}
	it = std::find(m_Walls.begin(), m_Walls.end(), wall - row);
	if (it != m_Walls.end())
	{
		return false;
	}
	it = std::find(m_Walls.begin(), m_Walls.end(), wall + row);
	if (it != m_Walls.end())
	{
		return false;
	}
	it = std::find(m_Walls.begin(), m_Walls.end(), wall + row + 1);
	if (it != m_Walls.end())
	{
		return false;
	}
	it = std::find(m_Walls.begin(), m_Walls.end(), wall + row - 1);
	if (it != m_Walls.end())
	{
		return false;
	}
	it = std::find(m_Walls.begin(), m_Walls.end(), wall - row + 1);
	if (it != m_Walls.end())
	{
		return false;
	}
	it = std::find(m_Walls.begin(), m_Walls.end(), wall - row - 1);
	if (it != m_Walls.end())
	{
		return false;
	}
	return true;
}

int Grid::findLocationOnGrid(Square* s)
{
	auto it = std::find(m_Squares.begin(), m_Squares.end(), s);
	if (it != m_Squares.end())
	{
		for (unsigned int pos{}; pos < m_Squares.size(); pos++)
		{
			if (m_Squares[pos] == s)
			{
				return pos;
			}
		}
	}
	return -1;
}
