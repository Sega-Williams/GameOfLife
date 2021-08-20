#include <vector>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <Windows.h>

using namespace std;
using namespace sf;

class Map
{
public:
	Map();
	int scrX = GetSystemMetrics(SM_CXSCREEN);
	int scrY = GetSystemMetrics(SM_CYSCREEN);
	int y = 1366;
	int x = 768;

	void checkMap();
	bool printMap(int i, int j) { return map[i][j]; }
	
	~Map();
private:
	int counter = 0;
	
	bool** map;
	bool** newMap;
	

};


