#include "Square.h"


Square::Square(Float2 botLeftpos, float width, float height)
	:m_BotLeft{ botLeftpos }
	, m_Width{ width }
	, m_Height{ height }
{}

Square::~Square()
{
	for (Square* s : m_Neigbor)
	{
		if (s != nullptr)
		{
			delete s;
			s = nullptr;
		}
	}
	m_Neigbor.clear();
}

void Square::Draw()
{
	Color3f color{};
	switch (m_State)
	{
	case TileState::actor:
		color = Color3f{0.f,0.8f,0.f};
		break;
	case TileState::notChecked:
		color = Color3f{ 0.2f,0.2f,0.2f };
		break;
	case TileState::checked:
		color = Color3f{ 0.6f,0.6f,0.6f };
		break;
	case TileState::wall:
		color = Color3f{ 1.f,1.f,1.f };
		break;
	case TileState::goal:
		color = Color3f{ 0.f,0.f,0.8f };
		break;	
	case TileState::path:
		color = Color3f{ 1.f,0.3f,0.8f };
		break;	
	case TileState::checkedNotPath:
		color = Color3f{ 1.f,1.f,0.8f };
		break;
	}
	glBegin(GL_POLYGON);
	glColor3f(color.r, color.g, color.b);
	glVertex2f(m_BotLeft.x, m_BotLeft.y);
	glVertex2f(m_BotLeft.x+m_Width, m_BotLeft.y);
	glVertex2f(m_BotLeft.x+m_Width, m_BotLeft.y+m_Height);
	glVertex2f(m_BotLeft.x, m_BotLeft.y + m_Height);
	glEnd();


	glBegin(GL_LINE_LOOP);
	glColor3f(0.8f, 0.f, 0.f);
	glVertex2f(m_BotLeft.x, m_BotLeft.y);
	glVertex2f(m_BotLeft.x + m_Width, m_BotLeft.y);
	glVertex2f(m_BotLeft.x + m_Width, m_BotLeft.y + m_Height);
	glVertex2f(m_BotLeft.x, m_BotLeft.y + m_Height);
	glEnd();
}


bool Square::operator<(Square rhs)
{
	return m_G < rhs.getG();
}