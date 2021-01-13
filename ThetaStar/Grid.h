#pragma once
#include "Includes.h"
#include <vector>
#include "Square.h"
class Grid
{
public:
	Grid(float,float,int,int, int amountWalls);
	~Grid();
	void Draw();
	void setSquareState(unsigned int pos, TileState state);
	std::vector<Square*> getNeighborFromPos(unsigned int pos);
	float getDistanceFromTo(int start, int end);
	Square* getGridSpot(unsigned int pos) { if (m_Squares.size() > pos) { return m_Squares[pos]; }return nullptr; };
	int findLocationOnGrid(Square*);
	std::vector<Square*> getSquares() { return m_Squares; };
	
private:
	float m_Width;
	float m_Height;
	int m_Rows;
	int m_Columns;
	std::vector<Square*> m_Squares{};
	std::vector<int> m_Walls{};
	int m_AmountWalls;

	void SetupgRid();
	void GenerateWalls(int amount, int row, int col);
	bool checkValidWall(int wall, int row);
};

