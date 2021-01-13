#pragma once
#include "Includes.h"
#include <vector>
class Circle
{
public:
	Circle(const float& x, const float& y,float* radius);
	void Draw(Color3f*);
	void setLoc(const Float2& loc) { m_Loc = loc; };
	~Circle();

private:
	Float2 m_Loc{};
	float* m_Radius{};
	std::vector<Float2> m_CirclePoints{};
};
