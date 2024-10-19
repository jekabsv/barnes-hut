#include "Init.hpp"

random_device rng;
mt19937 dev(rng());
int random(int low, int high)
{
	uniform_int_distribution<> var(low, high);
	return var(rng);
}