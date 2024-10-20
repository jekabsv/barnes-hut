#include "GQuad.hpp"
#include "BruteNGravitySim.hpp"

int screen_width;
int screen_height;

int main()
{



	Initialize(60);
	InitGQuad();

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


		StartGQuad();

	}
	//StartBruteNGravitySim();


	return 0;
}