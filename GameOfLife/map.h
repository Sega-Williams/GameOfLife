#include <vector>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Map
{
public:
	Map();
	const int y = 1366/4;
	const int x = 768/4;
	void nullNextGen();
	void checkMap();
	void updateMap();
	bool printMap(int i, int j);
	
private:
	int counter = 0;
	
	char** map;
	char** newMap;
	

};


