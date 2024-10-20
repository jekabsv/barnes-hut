#include "Init.hpp"

RenderWindow window(VideoMode(), "SuS", Style::Fullscreen);



void Initialize(int FrameRateLimit)
{	
	screen_width = window.getSize().x;
	screen_height = window.getSize().y;
	window.setFramerateLimit(FrameRateLimit);
}