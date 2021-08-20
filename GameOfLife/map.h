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
	const int y = 1366;
	const int x = 768;
	

	void checkMap();
	bool printMap(int i, int j) { return map[i][j]; }
	
	~Map();
private:
	int counter = 0;
	
	bool** map;
	bool** newMap;
	

};


