#include "GQuad.hpp"



void Quad::insert(Node* node)
{
	if (node == NULL)
		return;
	if (!inBoundary(node->pos))
		return;

	masscenter.x = (masscenter.x * mass + node->pos.x * node->data) / (node->data + mass);
	masscenter.y = (masscenter.y * mass + node->pos.y * node->data) / (node->data + mass);
	mass += node->data;


	if (abs(topLeft.x - botRight.x) <= 1
		&& abs(topLeft.y - botRight.y) <= 1) {
		if (n == NULL)
			n = node;
		return;
	}

	if ((topLeft.x + botRight.x) / 2 >= node->pos.x) {
		// Indicates topLeftTree
		if ((topLeft.y + botRight.y) / 2 >= node->pos.y) {
			if (topLeftTree == NULL)
				topLeftTree = new Quad(
					Vector2f(topLeft.x, topLeft.y),
					Vector2f((topLeft.x + botRight.x) / 2,
						(topLeft.y + botRight.y) / 2));
			topLeftTree->insert(node);
		}

		// Indicates botLeftTree
		else {
			if (botLeftTree == NULL)
				botLeftTree = new Quad(
					Vector2f(topLeft.x,
						(topLeft.y + botRight.y) / 2),
					Vector2f((topLeft.x + botRight.x) / 2,
						botRight.y));
			botLeftTree->insert(node);
		}
	}
	else {
		// Indicates topRightTree
		if ((topLeft.y + botRight.y) / 2 >= node->pos.y) {
			if (topRightTree == NULL)
				topRightTree = new Quad(
					Vector2f((topLeft.x + botRight.x) / 2,
						topLeft.y),
					Vector2f(botRight.x,
						(topLeft.y + botRight.y) / 2));
			topRightTree->insert(node);
		}

		// Indicates botRightTree
		else {
			if (botRightTree == NULL)
				botRightTree = new Quad(
					Vector2f((topLeft.x + botRight.x) / 2,
						(topLeft.y + botRight.y) / 2),
					Vector2f(botRight.x, botRight.y));
			botRightTree->insert(node);
		}
	}
}