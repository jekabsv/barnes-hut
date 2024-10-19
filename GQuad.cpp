#include "GQuad.hpp"




void StartGQuad()
{
	
	RenderWindow window(VideoMode(), "SuS", Style::Fullscreen);
	int screen_width = window.getSize().x;
	int screen_height = window.getSize().y;


	CircleShape testcircle;
	testcircle.setRadius(15);
	
	vector <Node> v;
	const int number = 10000;
	for (int i = 0; i < number; i++)
	{
		Node a(Vector2f(random(0, screen_width), random(0, screen_height)), 10);
		Node* pt = &a;
		v.push_back(a);
	}
	//window.display();
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		Quad center(Vector2f(0, 0), Vector2f(screen_width, screen_height));

		window.clear();
		for (int i = 0; i < v.size(); i++)
		{
			center.insert(&v[i]);
		}
		for (int i = 0; i < v.size(); i++)
		{
			center.search(&v[i]);
			if (v[i].pos.x >= screen_width || v[i].pos.x <= 0)
			{
				v[i].pos.y += v[i].vy;
				v[i].pos.x -= v[i].vx;
				v[i].vx *= -1;
			}
			else
			{
				if (v[i].pos.y >= screen_height || v[i].pos.y <= 0)
				{
					v[i].pos.x += v[i].vx;
					v[i].pos.y -= v[i].vy;
					v[i].vy *= -1;
				}
				else
				{
					v[i].pos.x += v[i].vx;
					v[i].pos.y += v[i].vy;
				}
			}
			
			v[i].shape.setPosition(v[i].pos);
			window.draw(v[i].shape);
		}
		testcircle.setPosition(center.masscenter);
		//window.draw(testcircle);
		window.display();



	}
}
