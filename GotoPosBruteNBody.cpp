#include "BruteNGravitySim.hpp"



void particle::gotopos(Vector2f pos, float mas)
{
	x += vx;
	y += vy;

	float diffx = x - pos.x;
	float diffy = y - pos.y;
	float dist = diffx * diffx + diffy * diffy;
	float force = mass * mas / dist;
	if (force >= mass)
	{
		force = mass;
	}
	float normalizedx = diffx * force / 1000;
	float normalizedy = diffy * force / 1000;
	vx *= 0.9999999999999;
	vy *= 0.9999999999999;
	vx -= normalizedx;
	vy -= normalizedy;

}