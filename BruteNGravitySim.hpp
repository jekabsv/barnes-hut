#include "Init.hpp"



class particle
{
public:
	float mass;
	float x = 0, y = 0;
	float vx = 0, vy = 0;
	CircleShape shape;
	particle()
	{
		x = 0;
		y = 0;
		vx = 0;
		vy = 0;
		mass = 1;
		shape.setRadius(2);
		shape.setOrigin(shape.getRadius(), shape.getRadius());
	}


	void gotopos(Vector2f pos, float mas);
	void update();


};

int StartBruteNGravitySim();