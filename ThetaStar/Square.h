#pragma once
#include "Includes.h"
#include <vector>

class Square
{
public:
	Square(Float2 botLeftpos,float width,float height);
	~Square();
	void setState(TileState state) { m_State = state; };
	Float2 getPositionMiddle() { return Float2{ m_BotLeft.x + (m_Width / 2.f),m_BotLeft.y + (m_Height / 2.f) }; };
	void addNeighbor(Square* neighBor) { m_Neigbor.push_back(neighBor); };
	void setParent(Square* parent) { m_Parent = parent; };
	void makeParentEmpty() { m_Parent = nullptr; };
	void setChild(Square* child) { m_Child = child; };
	std::vector<Square*> getNeighbors() { return m_Neigbor; };
	bool IsWall() { return m_State == TileState::wall; };
	Square* getParent() { return m_Parent; };
	void Draw();

	int getId() { return m_Id; };
	float getF() { return m_F; };
	void setF(float F) { m_F = F; };
	float getG() { return m_G; };
	void setG(float G) { m_G = G; };
	float getH() { return m_H; };
	void setH(float H) { m_H = H; };
	void setLeft(Square* left) { m_Left = left; };
	void setRight(Square* right) { m_Right = right; };
	void setBot(Square* bot) { m_Bot = bot; };
	void setTop(Square* top) { m_Top = top; };
	void setId(int id) { m_Id = id; };

	Square* getLeft() { return m_Left; };
	Square* getRight() { return m_Right; };
	Square* getBot() { return m_Bot; };
	Square* getTop() { return m_Top; };

	bool operator<(Square rhs);

private:
	Float2 m_BotLeft{};
	float m_Width{};
	float m_Height{};
	TileState m_State{TileState::notChecked};
	std::vector<Square*> m_Neigbor{};
	float m_F{};//cumulative cost 
	float m_H{};//heuristic
	float m_G{};//node cost
	int m_Id{};
	Square* m_Left = nullptr;
	Square* m_Right = nullptr;
	Square* m_Top = nullptr;
	Square* m_Bot = nullptr;

	Square* m_Parent = nullptr;
	Square* m_Child = nullptr;
};

