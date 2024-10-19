//#include "Init.hpp"
//#include "inf.hpp"
//
//
//int main()
//{
//    RectangleShape slider;
//    RectangleShape button;
//
//
//
//    float speed = 1;
//    Font font;
//    font.loadFromFile("C:/Users/jekabs.vidrusks/Downloads/Roboto/Roboto-Black.ttf");
//
//    Text text("hello", font);
//    text.setCharacterSize(30);
//    text.setStyle(Text::Bold);
//    text.setFillColor(Color::White);
//    Text text2("hello", font);
//    text2.setCharacterSize(30);
//    text2.setStyle(Text::Bold);
//    text2.setFillColor(Color::White);
//    Text sped("hello", font);
//    sped.setCharacterSize(30);
//    sped.setStyle(Text::Bold);
//    sped.setFillColor(Color::White);
//
//    RenderWindow window(VideoMode(), "app.exe", Style::Fullscreen);
//    window.setFramerateLimit(60);
//    int screen_width = window.getSize().x;
//    int screen_height = window.getSize().y;
//    RectangleShape signal;
//    RectangleShape real;
//    Color color = Color(255, 0, 0);
//
//    vector <inf> q;
//    inf add;
//
//    float distance = -1;
//    signal.setSize(Vector2f(500, 500));
//    signal.setOrigin(signal.getSize().x/2, signal.getSize().y/2);
//    signal.setPosition(screen_width / 2 - 250, screen_height / 2);
//    real.setSize(Vector2f(200, 200));
//    real.setOrigin(real.getSize().x / 2, real .getSize().y / 2);
//    real.setPosition(screen_width / 2 +500, screen_height / 2-350);
//    text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
//    text.setPosition(screen_width / 2 - 550, screen_height / 2 - 300);
//    text2.setOrigin(text2.getLocalBounds().width / 2, text2.getLocalBounds().height / 2);
//    text2.setPosition(screen_width / 2 + 650, screen_height / 2 - 270);
//    sped.setOrigin(sped.getLocalBounds().width / 2, sped.getLocalBounds().height / 2);
//    sped.setPosition(screen_width / 2 - 800, screen_height / 2 - 300);
//    slider.setSize(Vector2f(15, 500));
//    slider.setOrigin(slider.getSize().x / 2, slider.getSize().y / 2);
//    slider.setPosition(screen_width / 2 - 800, screen_height / 2);
//    button.setSize(Vector2f(50, 10));
//    button.setOrigin(button.getSize().x / 2, button.getSize().y / 2);
//    button.setPosition(screen_width / 2 - 800, screen_height / 2);
//
//    int go = 0;
//    int r, g, b;
//    r = 255;
//    g = 0;
//    b = 0;
//    int del = -1;
//    while (window.isOpen())
//    {
//        Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//        if (event.type == sf::Event::MouseButtonPressed)
//        {
//            if (event.mouseButton.button == sf::Mouse::Left && Mouse::getPosition().y < button.getPosition().y+5 && Mouse::getPosition().y > button.getPosition().y - 5 && 
//                Mouse::getPosition().x < button.getPosition().x+25 && Mouse::getPosition().x > button.getPosition().x - 25)
//            {
//                button.setFillColor(Color(128, 128, 128));
//                go = 1;
//            }
//        }
//        if (event.type == sf::Event::MouseButtonReleased)
//        {
//            if (event.mouseButton.button == sf::Mouse::Left)
//            {
//                button.setFillColor(Color(255, 255, 255));
//                go = 0;
//            }
//        }
//
//        if (go && button.getPosition().y >= slider.getPosition().y - 250 && button.getPosition().y <= slider.getPosition().y + 250)
//        {
//            button.setPosition(button.getPosition().x, Mouse::getPosition().y);
//            //cout << "hi" << endl;
//        }
//        if (button.getPosition().y < slider.getPosition().y - 250)
//        {
//            button.setPosition(button.getPosition().x, slider.getPosition().y-240);
//        }
//        if (button.getPosition().y > slider.getPosition().y + 250)
//        {
//            button.setPosition(button.getPosition().x, slider.getPosition().y + 240);
//        }
//
//        if (r == 255 && g < 255 && b == 0)
//        {
//            g += 1;
//        }
//        if (r > 0 && g == 255 && b == 0)
//        {
//            r -= 1;
//        }
//        if (r == 0 && g == 255 && b < 255)
//        {
//            b += 1;
//        }
//        if (r == 0 && g > 0 && b == 255)
//        {
//            g -= 1;
//        }
//        if (r < 255 && g == 0 && b == 255)
//        {
//            r += 1;
//        }
//        if (r == 255 && g == 0 && b > 0)
//        {
//            b -= 1;
//        }
//        distance += speed;
//
//
//        speed = (500 - button.getPosition().y) * 0.010 + 1;
//
//
//
//
//        //cout << r << ' ' << g << ' ' << b << endl;
//
//        del = -1;
//        for (int i = 0; i < q.size(); i++)
//        {
//            cout << q[i].time << ' ';
//            q[i].time--;
//            if (q[i].time <= 0)
//            {
//                signal.setFillColor(Color(q[i].r, q[i].g, q[i].b));
//                string s = to_string(q[i].dist);
//                text.setString(s);
//                del = i;
//            }
//        }
//        cout << endl;
//        if (del > -1)
//        {
//            q.erase(q.begin()+del);
//        }
//        del = -1;
//        for (int i = 0; i < q.size(); i++)
//        {
//            if (q[i].time <= 0)
//            {
//                signal.setFillColor(Color(q[i].r, q[i].g, q[i].b));
//                string s = to_string(q[i].dist);
//                text.setString(s);
//                del = i;
//                break;
//            }
//        }
//        //cout << endl;
//        if (del > -1)
//        {
//            q.erase(q.begin() + del);
//        }
//        add.r = r;
//        add.g = g;
//        add.b = b;
//        add.dist = distance;
//        add.time = distance;
//        q.push_back(add);
//
//        string a = "v: ";
//        string spd = to_string(speed);
//        spd = a + spd;
//        string s2 = to_string(distance);
//        text2.setString(s2);
//        sped.setString(spd);
//
//        
//
//
//
//        //cout << r << ' ' << g << ' ' << b << endl;
//        real.setFillColor(Color(r, g, b));
//        
//        window.clear();
//
//        window.draw(signal);
//        window.draw(real);
//        window.draw(text);
//        window.draw(text2);
//        window.draw(slider);
//        window.draw(button);
//        window.draw(sped);
//        window.display();
//
//
//
//
//
//    }
//	return 0;
//
//}
//
//












//#include "Init.hpp"
//using namespace std;
//
//class Node
//{
//public:
//	Vector2f pos;
//	int data;
//	Node(Vector2f initpos, int initdata)
//	{
//		pos = initpos;
//		data = initdata;
//	}
//	Node()
//	{
//		data = 0;
//	}
//};
//
//
//class Quad {
//	Vector2f topLeft;
//	Vector2f botRight;
//
//	Node* n;
//
//	Quad* topLeftTree;
//	Quad* topRightTree;
//	Quad* botLeftTree;
//	Quad* botRightTree;
//
//public:
//	Quad()
//	{
//		topLeft = Vector2f(0, 0);
//		botRight = Vector2f(0, 0);
//		n = NULL;
//		topLeftTree = NULL;
//		topRightTree = NULL;
//		botLeftTree = NULL;
//		botRightTree = NULL;
//	}
//	Quad(Vector2f topL, Vector2f botR)
//	{
//		n = NULL;
//		topLeftTree = NULL;
//		topRightTree = NULL;
//		botLeftTree = NULL;
//		botRightTree = NULL;
//		topLeft = topL;
//		botRight = botR;
//	}
//	bool inBoundary(Vector2f p)
//	{
//		return (p.x >= topLeft.x && p.x <= botRight.x && p.y >= topLeft.y && p.y <= botRight.y);
//	}
//	void insert(Node* node)
//	{
//		if (node == NULL)
//			return;
//
//		if (!inBoundary(node->pos))
//			return;
//
//		if (abs(topLeft.x - botRight.x) <= 1
//			&& abs(topLeft.y - botRight.y) <= 1) {
//			if (n == NULL)
//				n = node;
//			return;
//		}
//
//		if ((topLeft.x + botRight.x) / 2 >= node->pos.x) {
//			if ((topLeft.y + botRight.y) / 2 >= node->pos.y) {
//				if (topLeftTree == NULL)
//					topLeftTree = new Quad(
//						Vector2f(topLeft.x, topLeft.y),
//						Vector2f((topLeft.x + botRight.x) / 2,
//							(topLeft.y + botRight.y) / 2));
//				topLeftTree->insert(node);
//			}
//
//			else {
//				if (botLeftTree == NULL)
//					botLeftTree = new Quad(
//						Vector2f(topLeft.x,
//							(topLeft.y + botRight.y) / 2),
//						Vector2f((topLeft.x + botRight.x) / 2,
//							botRight.y));
//				botLeftTree->insert(node);
//			}
//		}
//		else {
//			if ((topLeft.y + botRight.y) / 2 >= node->pos.y) {
//				if (topRightTree == NULL)
//					topRightTree = new Quad(
//						Vector2f((topLeft.x + botRight.x) / 2,
//							topLeft.y),
//						Vector2f(botRight.x,
//							(topLeft.y + botRight.y) / 2));
//				topRightTree->insert(node);
//			}
//			else {
//				if (botRightTree == NULL)
//					botRightTree = new Quad(
//						Vector2f((topLeft.x + botRight.x) / 2,
//							(topLeft.y + botRight.y) / 2),
//						Vector2f(botRight.x, botRight.y));
//				botRightTree->insert(node);
//			}
//		}
//	}
//	- search(Vector2f p)
//	{
//		if (!inBoundary(p))
//			return NULL;
//		if (n != NULL)
//			return n;
//
//		if ((topLeft.x + botRight.x) / 2 >= p.x) {
//			if ((topLeft.y + botRight.y) / 2 >= p.y) {
//				if (topLeftTree == NULL)
//					return NULL;
//				return topLeftTree->search(p);
//			}
//			else {
//				if (botLeftTree == NULL)
//					return NULL;
//				return botLeftTree->search(p);
//			}
//		}
//		else {
//			if ((topLeft.y + botRight.y) / 2 >= p.y) {
//				if (topRightTree == NULL)
//					return NULL;
//				return topRightTree->search(p);
//			}
//			else {
//				if (botRightTree == NULL)
//					return NULL;
//				return botRightTree->search(p);
//			}
//		}
//	};
//};
//
//
//int main()
//{
//	Quad center(Vector2f(0, 0), Vector2f(8, 8));
//	Node a(Vector2f(1, 1), 1);
//	Node b(Vector2f(2, 5), 2);
//	Node c(Vector2f(7, 6), 3);
//	center.insert(&a);
//	center.insert(&b);
//	center.insert(&c);
//	cout << "Node a: " << center.search(Vector2f(1, 1))->data
//		<< "\n";
//	cout << "Node b: " << center.search(Vector2f(2, 5))->data
//		<< "\n";
//	cout << "Node c: " << center.search(Vector2f(7, 6))->data
//		<< "\n";
//	cout << "Non-existing node: "
//		<< center.search(Vector2f(5, 5));
//	return 0;
//}

















	



/*
#include <iostream>

using namespace std;

const int N = 1e5 + 5;

int segt[4 * N], n;

// !!! segments pos ar intervalu [l;r] skelas uz diviem intervaliem
// kreisa puse: [l;mid] pos*2
// laba puse: [mid+1,r] pos*2+1

void seti(int i, int v, int l = 1, int r = n, int pos = 1) // segt[pos] = sum(l,r)
{
	for (int i = 0; i < n; i++)
	{
		cout << segt[i] << ' ';
	}
	cout << endl;
	// vienmer l <= i && i <= r

	//1. esam sasniegusi galamerki
	if (l == r)
	{
		segt[pos] = v;
	}
	else //2. skelamies talak
	{
		int mid = (l + r) / 2;
		if (i <= mid) // skelam uz [l;mid]
		{
			seti(i, v, l, mid, pos * 2);
		}
		else // skelam uz [mid+1;r]
		{
			seti(i, v, mid + 1, r, pos * 2 + 1);
		}
		segt[pos] = segt[pos * 2] + segt[pos * 2 + 1];
	}
}

int getsum(int lb, int rb, int l = 1, int r = n, int pos = 1)
{
	if (rb < l || r < lb) // vispar neinterese [l;r]
	{
		return 0;
	}
	else if (lb <= l && r <= rb) // interese viss intervals [l;r]
	{
		return segt[pos];
	}
	else // interese tikai dala no [l;r]
	{
		int mid = (l + r) / 2;
		int lsum = getsum(lb, rb, l, mid, pos * 2);
		int rsum = getsum(lb, rb, mid + 1, r, pos * 2 + 1);
		return lsum + rsum;
	}
}

int main()
{
	n = 6;
	seti(1, 1);
	seti(2, 2);
	seti(3, 3);
	seti(4, 4);
	seti(5, 5);
	seti(6, 6);

	
	for (int i = 0; i < n; i++)
	{
		cout << segt[i] << ' ';
	}
	return 0;
}*/