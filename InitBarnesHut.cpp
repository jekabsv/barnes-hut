#include "GQuad.hpp"

vector <Node> v;
int number = 1000;
CircleShape testcircle(2);

void InitGQuad()
{
	
	
	
	testcircle.setRadius(15);
	for (int i = 0; i < number; i++)
	{
		Node a(Vector2f(random(0, screen_width), random(0, screen_height)), 10);
		Node* pt = &a;
		v.push_back(a);
	}



}


 