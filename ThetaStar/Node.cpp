#include "Node.h"

Node::Node(int id, Float2 pos, float* radius, Color3f* emptyColor, Color3f* fullColor)
	:m_Id{id}
	, m_Pos{pos}
	, m_EmptyNode{emptyColor}
	, m_FullNode{fullColor}
	, m_PossibleConnections{0}
{
	m_ActorOnNode = false;
	m_Circle = new Circle{ pos.x,pos.y,radius };
}

Node::~Node()
{
	if (m_Circle)
	{
		delete m_Circle;
	}
}

void Node::setActorOnNode(bool isThereActorOnNode)
{
	m_ActorOnNode = isThereActorOnNode;
}

void Node::Draw()
{
	
	
	if (m_ActorOnNode)
	{
		m_Circle->Draw(m_FullNode);
	}
	else
	{
		m_Circle->Draw(m_EmptyNode);
	}
	DrawConnections();
}

void Node::addConnectionToNode(Node* node)
{
	m_Connections.push_back(node);
}

void Node::DrawConnections()
{
	for (Node* node : m_Connections)
	{
		glBegin(GL_LINE_LOOP);
		glLineWidth(2.f);
		glColor3f(0.7f,0.7f,0.7f);
		glVertex2f(m_Pos.x, m_Pos.y);
		glVertex2f(node->getPosition().x, node->getPosition().y);
		glEnd();
	}
}

Float2 Node::getPosition()
{
	return m_Pos;
}
