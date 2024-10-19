#include "Init.hpp"


int random(int low, int high);



struct Node {
	Vector2f pos;
	int data;
	CircleShape shape;
	float vx, vy;
	Node(Vector2f _pos, int _data)
	{
		vx = 0;
		vy = 0;
		pos = _pos;
		data = _data;
		shape.setRadius(1);
		shape.setPosition(pos);
	}
	Node() { data = 0; }
};


class Quad {
	Vector2f topLeft;
	Vector2f botRight;

	Node* n;

	Quad* topLeftTree;
	Quad* topRightTree;
	Quad* botLeftTree;
	Quad* botRightTree;


	
	float mass;

public:
	Vector2f masscenter;
	Quad()
	{
		mass = 0;
		masscenter = Vector2f(0, 0);
		topLeft = Vector2f(0, 0);
		botRight = Vector2f(0, 0);
		n = NULL;
		topLeftTree = NULL;
		topRightTree = NULL;
		botLeftTree = NULL;
		botRightTree = NULL;
	}
	Quad(Vector2f topL, Vector2f botR)
	{
		mass = 0;
		masscenter = Vector2f(0, 0);
		n = NULL;
		topLeftTree = NULL;
		topRightTree = NULL;
		botLeftTree = NULL;
		botRightTree = NULL;
		topLeft = topL;
		botRight = botR;
	}
	void insert(Node*);
	void search(Node*);
	bool inBoundary(Vector2f);
};


void StartGQuad();
