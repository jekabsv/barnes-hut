#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;
using namespace sf;

int random(int low, int high);

void Initialize(int FrameRateLimit);

extern RenderWindow window;

extern int screen_width;
extern int screen_height;
