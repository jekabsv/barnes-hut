#include "BruteNGravitySim.hpp"



int StartBruteNGravitySim()
{
	vector <particle> p;
	const int number = 1000;
	particle add;
	for (int i = 0; i < number; i++)
	{
		p.push_back(add);
		p[i].x = random(0, screen_width);
		p[i].y = random(0, screen_height);
		p[i].update();
	}
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		Vector2f mpos(Mouse::getPosition().x, Mouse::getPosition().y);
		for (int i = 0; i < number; i++)
		{
			for (int j = 0; j < number; j++)
			{
				if (i != j)
				{
					p[i].gotopos(Vector2f(p[j].x, p[j].y), p[j].mass);
					p[i].update();
				}
			}
		}
		/*for (int j = 0; j < number; j++)
		{
			p[j].gotopos(mpos, 20000);
			p[j].update();
		}*/
		window.clear();
		for (int j = 0; j < number; j++)
		{
			window.draw(p[j].shape);
		}
		//cout << p[1].x << ' ' << p[1].y << endl;
		window.display();
	}
	return 0;
}
