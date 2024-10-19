#include "GQuad.hpp"


bool Quad::inBoundary(Vector2f p)
{
	return (p.x >= topLeft.x && p.x <= botRight.x
		&& p.y >= topLeft.y && p.y <= botRight.y);
}