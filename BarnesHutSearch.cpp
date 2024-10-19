#include "GQuad.hpp"


void Quad::search(Node* node)
{
	const float k = 0.5;
	const int strenght = 10;
	const float air = 0.9999;


	/*if (!inBoundary(node->pos))
		return;*/

	if (n != NULL && n != node)
	{
		//cout << "Heloo\n";
		float diffx = node->pos.x - n->pos.x;
		float diffy = node->pos.y - n->pos.y;
		float dist = diffx * diffx + diffy * diffy;
		float normalizedx = diffx / dist;
		float normalizedy = diffy / dist;
		/*cout << dist << endl;
		sleep(seconds(1));*/
		node->vx *= air;
		node->vy *= air;
		node->vx -= normalizedx / strenght;
		node->vy -= normalizedy / strenght;

		//force to n
		return;
	}

	float diffx = masscenter.x - node->pos.x;
	float diffy = masscenter.y - node->pos.y;
	float dist = diffx * diffx + diffy * diffy;
	if ((botRight.x - topLeft.x) * (botRight.x - topLeft.x) / dist < k * k)
	{
		float diffx = node->pos.x - masscenter.x;
		float diffy = node->pos.y - masscenter.y;
		float dist = diffx * diffx + diffy * diffy;
		float normalizedx = diffx / dist;
		float normalizedy = diffy / dist;
		/*cout << dist << endl;
		sleep(seconds(1));*/
		node->vx *= air;
		node->vy *= air;
		node->vx -= normalizedx / strenght;
		node->vy -= normalizedy / strenght;

		return;
	}
	else
	{
		if (topLeftTree != NULL)
			topLeftTree->search(node);
		if (botLeftTree != NULL)
			botLeftTree->search(node);
		if (topRightTree != NULL)
			topRightTree->search(node);
		if (botRightTree != NULL)
			botRightTree->search(node);
	}

};




