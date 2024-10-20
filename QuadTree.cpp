/*
#include "Init.hpp"

RenderWindow window(VideoMode(), "SuS", Style::Fullscreen);
int screen_width = window.getSize().x;
int screen_height = window.getSize().y;

random_device rng;
mt19937 dev(rng());



void draw(Vector2f BR, Vector2f TL)
{
	return;
	RectangleShape rect;
	rect.setFillColor(Color::Transparent);
	rect.setOutlineColor(Color(0, 255, 0));
	rect.setOutlineThickness(1);
	rect.setOrigin(0, 0);

	rect.setSize(Vector2f((BR.x - TL.x) / 2, (BR.y - TL.y) / 2));
	rect.setPosition((BR.x - TL.x) / 2 + TL.x, TL.y);
	window.draw(rect);
	rect.setPosition((BR.x - TL.x) / 2 + TL.x, (BR.y - TL.y) / 2 + TL.y);
	window.draw(rect);
	rect.setPosition(TL.x, TL.y);
	window.draw(rect);
	rect.setPosition(TL.x, (BR.y - TL.y) / 2 + TL.y);
	window.draw(rect);
}



int random(int low, int high)
{
	uniform_int_distribution<> var(low, high);
	return var(rng);
}





class Particle
{
public:
	CircleShape shape;
	Vector2f pos;
	int n;
	Particle(Vector2f initpos, int initn)
	{
		pos = initpos;
		n = initn;
		shape.setRadius(1);
		shape.setPosition(pos);
		window.draw(shape);
	}
};




class Quad
{


	Vector2f TL, BR;
	Particle* particle;
	Quad* TRQuad;
	Quad* TLQuad;
	Quad* BRQuad;
	Quad* BLQuad;


public:
	Quad()
	{
		TL = Vector2f(0, 0);
		BR = Vector2f(0, 0);
		TRQuad = NULL;
		TLQuad = NULL;
		BRQuad = NULL;
		BLQuad = NULL;
		particle = NULL;
	}
	Quad(Vector2f TRinit, Vector2f BLinit)
	{
		TL = TRinit;

		BR = BLinit;
		TRQuad = NULL;
		TLQuad = NULL;
		BRQuad = NULL;
		BLQuad = NULL;
		particle = NULL;
	}


	void insert(Particle* node)
	{
		if (node == NULL)
		{
			cout << "error!";
			return;
		}
		if (!(node->pos.x >= 0 && node->pos.y >= 0 && node->pos.x > 0 && node->pos.x <= screen_width && node->pos.y <= screen_height))
		{
			//cout << "error!";
			return;
		}
		if (abs(TL.x - BR.x) <= 1 && abs(TL.y - BR.y <= 1))
		{
			if (particle == NULL)
			{
				draw(BR, TL);
				//cout << "hello";
				particle = node;
			}
			else
			{
				//cout << "error";
				return;
			}
		}
		if (node->pos.x > abs(BR.x - TL.x) / 2 + TL.x)
		{
			if (node->pos.y < abs(BR.y - TL.y) / 2 + TL.y)
			{
				if (TRQuad == NULL)
				{
					draw(BR, TL);
					//cout << "hello1"
					//cout << BR.x << ' ' << BR.y << "     " << TL.x << ' ' << TL.y << endl;
					TRQuad = new Quad(Vector2f((BR.x - TL.x) / 2 + TL.x, TL.y), Vector2f(BR.x, (BR.y - TL.y) / 2 + TL.y));
				}
				else
				{
					//cout << "nah";
					draw(BR, TL);
					TRQuad->insert(node);
				}
			}
			else
			{
				if (BRQuad == NULL)
				{
					draw(BR, TL);
					//cout << "hello2";
					BRQuad = new Quad(Vector2f((BR.x - TL.x) / 2 + TL.x, (BR.y - TL.y) / 2 + TL.y), Vector2f(BR.x, BR.y));
				}
				else
				{
					//cout << "nah";
					draw(BR, TL);
					BRQuad->insert(node);
				}
			}
		}
		else
		{
			if (node->pos.y < abs(BR.y - TL.y) / 2 + TL.y)
			{
				if (TLQuad == NULL)
				{
					draw(BR, TL);
					//cout << "hello3";
					TLQuad = new Quad(Vector2f(TL.x, TL.y), Vector2f((BR.x - TL.x) / 2 + TL.x, (BR.y - TL.y) / 2 + TL.y));
				}
				else
				{
					//cout << "nah";
					draw(BR, TL);
					TLQuad->insert(node);
				}
			}
			else
			{
				if (BLQuad == NULL)
				{
					draw(BR, TL);
					//cout << "hello4";
					BLQuad = new Quad(Vector2f(TL.x, (BR.y - TL.y) / 2 + TL.y), Vector2f((BR.x - TL.x) / 2 + TL.x, BR.y));
				}
				else
				{
					//cout << "nah";
					draw(BR, TL);
					BLQuad->insert(node);
				}
			}
		}
	}
};





int StartQuadTree()
{
	Clock clock;
	RectangleShape testrect;
	testrect.setSize(Vector2f(50, 50));
	testrect.setPosition(960, 0);
	testrect.setFillColor(Color::Red);
	window.clear();
	Quad test(Vector2f(0, 0), Vector2f(screen_width, screen_height));

	/*test.insert(pt);
	a.pos = Vector2f(5, 1000);
	test.insert(pt);
	a.pos = Vector2f(10, 1000);
	test.insert(pt);
	a.pos = Vector2f(random(0, screen_width), random(0, screen_height));
	test.insert(pt);
	a.pos = Vector2f(random(0, screen_width), random(0, screen_height));
	test.insert(pt);
	a.pos = Vector2f(random(0, screen_width), random(0, screen_height));
	test.insert(pt);
	a.pos = Vector2f(random(0, screen_width), random(0, screen_height));
	test.insert(pt);
	a.pos = Vector2f(random(0, screen_width), random(0, screen_height));
	test.insert(pt);
	a.pos = Vector2f(random(0, screen_width), random(0, screen_height));
	test.insert(pt);
	a.pos = Vector2f(random(0, screen_width), random(0, screen_height));
	test.insert(pt);
	a.pos = Vector2f(random(0, screen_width), random(0, screen_height));
	test.insert(pt);
	a.pos = Vector2f(random(0, screen_width), random(0, screen_height));
	test.insert(pt);*./

	window.draw(testrect);




	window.display();

	vector <Particle> p;
	const int number = 500000;



	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		//window.draw(rect);

		for (int i = 0; i < number; i++)
		{
			Particle a(Vector2f(random(0, 
			_width), random(0, screen_height)), 10);
			Particle* pt = &a;
			p.push_back(a);
			test.insert(pt);

		}
		window.display();
		//sleep(seconds(2));
		Time time = clock.getElapsedTime();
		cout << time.asSeconds() << endl;
		p.clear();
		clock.restart();


	}




	return 0;
}

*/