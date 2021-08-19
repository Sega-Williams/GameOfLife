#include <SFML/Graphics.hpp>
#include <iostream>
#include "map.h"

using namespace std;
using namespace sf;


void checkMapThread(Map& map);



int main()
{
	

	srand(time(0));
	sf::RenderWindow window(sf::VideoMode(1366, 768), "SFML works!");
	sf::Event event;
	View view;
	view.reset(FloatRect(0, 0, (1366 / 4)*10, (768/4)*10));
	

	Image world_image;
	world_image.loadFromFile("images/square.bmp");
	Texture world;
	world.loadFromImage(world_image);
	Sprite s_world;
	s_world.setTexture(world);
	Map map;
	sf::Clock clock;
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

		window.display();
		window.setFramerateLimit(60);
		
		Thread thread(&checkMapThread, map);
		thread.launch();

		
		
	}

	return 0;
}


void checkMapThread(Map& map) {
	
	Mutex mut;
	mut.lock();

	map.checkMap();
	
	mut.lock();

	map.updateMap();
	map.nullNextGen();
}

