#pragma once

#include "Circle.h"
#include <vector>

class Node
{
public:
	Node(int id, Float2 pos,float* radius, Color3f* emptyColor, Color3f* fullColor);
	~Node();
	int getId() { return m_Id; };
	void Draw();
	void setActorOnNode(bool);
	void addConnectionToNode(Node* node);
	Float2 getPosition();
	void setPossibleConnections(int connections) { m_PossibleConnections = connections; };
	int getPossibleConnections() { return m_PossibleConnections; };
	int getCurrentConnections(std::vector<Node*>& nodes) { nodes = m_Connections; return int(m_Connections.size()); }
	std::vector<Node*> getConnectionsVector() { return m_Connections; };
	bool checkId(int id) { return id == m_Id; };
private:
	int m_Id;
	Float2 m_Pos;
	Circle* m_Circle = nullptr;
	bool m_ActorOnNode{};
	std::vector<Node*> m_Connections{};
	Color3f* m_EmptyNode;
	Color3f* m_FullNode;
	int m_PossibleConnections;
	

	void DrawConnections();
};
