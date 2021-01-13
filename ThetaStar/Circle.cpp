#include "Circle.h"


Circle::Circle(const float& x, const float& y, float* radius)
	:m_Radius{ radius }
{
	m_Loc.x = x;
	m_Loc.y = y;

}
void Circle::Draw(Color3f* color)
{

	glBegin(GL_POLYGON);
	glColor3f(color->r, color->g,color->b);
	for (int i{}; i < 360; i ++)
	{
		float radians{ (i) * 0.0174532925f };
		Float2 f{};
		f.x = m_Loc.x + *m_Radius * cosf(radians);
		f.y = m_Loc.y + *m_Radius * sinf(radians);

		glVertex2f(f.x, f.y);
	}
	glEnd();
}

Circle::~Circle()
{
	if (m_Radius)
	{
		delete m_Radius;
	}
}
