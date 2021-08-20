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
	/*const int y = 1366;
	const int x = 768;*/
	const int y = 200;
	const int x = 200;

	void checkMap();
	/*void updateMap();*/
	bool printMap(int i, int j) { return map[i][j]; }
	
private:
	int counter = 0;
	
	bool** map;
	bool** newMap;
	

};


