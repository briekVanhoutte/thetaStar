#include "Program.h"
#include <algorithm>

Program::Program()
{
	m_World = new World{float(m_Width),float(m_Height),int(m_Width / m_SquareSize),int(m_Height/ m_SquareSize)};
	m_Solver = new Solver{};
	std::vector<int> path = m_Solver->SolveThetaStar(m_World->getActor(),m_World->getGrid());
	for (unsigned int idx{1};idx<path.size();idx++)
	{
		
		m_World->getGrid()->getGridSpot(path[idx])->setState(TileState::path);
		
	}
}

Program::~Program()
{
	if (m_World)
	{
		delete m_World;
	}	
	if (m_Solver)
	{
		delete m_Solver;
	}
}


void Program::Draw()
{
	m_World->Draw();
}

void Program::Update(float elapsedSeconds)
{
	
}
