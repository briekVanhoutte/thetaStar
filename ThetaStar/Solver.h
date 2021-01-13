#pragma once
#include"Includes.h"
#include "Actor.h"
#include "Grid.h"
#include <vector>
#include <map>

class Solver
{
public:
	Solver();
	~Solver();

	std::vector<int> SolveThetaStar(Actor* actor, Grid* grid);
	
private:
	std::vector<Square*> m_Path{};
	int m_StartPos{};
	int m_EndPos{};
	//std::map<Square*, float>m_Open{};
	std::vector<Square*> m_Open{};
	std::vector<Square*> m_Closed{};
	/*std::map<Square*, float> m_Closed{};*/

	float CalcgScore(int pos, int startPos, Grid* grid);
	float Calcheuristic(int pos, int endPos, Grid* grid);
	Square* PopBack(std::vector<Square*>& vector);
	Square* reconstructPath(Square* s);
	void update_vertex(Square* s, Square* neighbor, Grid* grid);
	bool line_of_sight(Square*, Square*);
	void setDistances(Grid*);
	void sortOpen();
};

