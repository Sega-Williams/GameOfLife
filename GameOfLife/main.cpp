#include <SFML/Graphics.hpp>
#include <iostream>
#include "map.h"
#include <Windows.h>

using namespace std;
using namespace sf;


void checkMapThread(Map& map);

const double PI = acos(-1.0);

int main()
{
	srand(time(0));
	
	//Create Texture
	Image world_image;
	world_image.loadFromFile("images/square.bmp");
	Texture world;
	world.loadFromImage(world_image);
	Sprite s_world;
	s_world.setTexture(world);

	//Render Window by screen
	int scrX = GetSystemMetrics(SM_CXSCREEN);
	int scrY = GetSystemMetrics(SM_CYSCREEN);
	sf::RenderWindow window(sf::VideoMode(scrX, scrY), "Game of Life");
	sf::Event event;
	
	Map map;
	int width = map.y;
	int height = map.x;

	View view;
	view.reset(FloatRect(0, 0, (width)*10, (height)*10));
	
	Thread thread(&checkMapThread, map);
	Mutex mut;
	
	while (window.isOpen())
	{
		
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		window.setView(view);
		window.clear();
		
		mut.lock();
		
		for (int i = 0; i < map.y; i++)
		{
			for (int j = 0; j < map.x; j++)
			{
				if (map.printMap(i, j)) s_world.setTextureRect(IntRect(0, 0, 10, 10));
				else s_world.setTextureRect(IntRect(10, 0, 10, 10));

				s_world.setPosition(i * 10, j * 10);
				window.draw(s_world);
			}
		}
		
		mut.unlock();
		thread.launch();
		window.display();
		window.setFramerateLimit(60);
		
	}
	return 0;
}

void checkMapThread(Map& map) {
	Mutex mut;
	mut.lock();
	map.checkMap();
	mut.unlock();
}


