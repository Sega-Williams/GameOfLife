#include "map.h"
Map::Map() {
	
	map = new char* [y];
	for (int i = 0; i < y; i++) map[i] = new char[x];
	newMap = new char * [y];
	for (int i = 0; i < y; i++) newMap[i] = new char[x];
	
	
	//Generator
	
	for (int i = 0; i < y; i++){
		for (int j = 0; j < x; j++)
		{
			if (rand() % 2 == 1) map[i][j] = '@';
			else map[i][j] = ' ';
			newMap[i][j] = 0;
		}
	}
	/*for (int i = 0; i < y; i++){
		for (int j = 0; j < x; j++)
		{
			map[i][j] = ' ';
			newMap[i][j] = 0;
		}
	}
	map[1][2] = '@';
map[2][2] = '@';
map[3][2] = '@';
map[19][20] = '@';
map[20][20] = '@';
map[20][18] = '@';
map[21][20] = '@';
map[21][19] = '@';*/
}

void Map::nullNextGen() {
	//Обнуление карты следующей генерации
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			newMap[i][j] = 0;	
		}	
	}
}

void Map::checkMap() {
	//Проверка карты
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			//Верхняя грань
			if (i == 0 && (j != 0 && j != x - 1)) {
				if (map[y - 1][j - 1] == '@') counter++;
				if (map[y - 1][j] == '@') counter++;
				if (map[y - 1][j + 1] == '@') counter++;
				if (map[i][j - 1] == '@') counter++;
				if (map[i][j + 1] == '@') counter++;
				if (map[i + 1][j - 1] == '@') counter++;
				if (map[i + 1][j] == '@') counter++;
				if (map[i + 1][j + 1] == '@') counter++;
			}
			//Нижняя грань
			if (i == y - 1 && (j != 0 && j != x - 1)) {
				if (map[i - 1][j - 1] == '@') counter++;
				if (map[i - 1][j] == '@') counter++;
				if (map[i - 1][j + 1] == '@') counter++;
				if (map[i][j - 1] == '@') counter++;
				if (map[i][j + 1] == '@') counter++;
				if (map[0][j - 1] == '@') counter++;
				if (map[0][j] == '@') counter++;
				if (map[0][j + 1] == '@') counter++;
			}
			//Левая грань
			if ((i != 0 && i != y - 1) && j == 0) {
				if (map[i - 1][x - 1] == '@') counter++;
				if (map[i - 1][j] == '@') counter++;
				if (map[i - 1][j + 1] == '@') counter++;
				if (map[i][x - 1] == '@') counter++;
				if (map[i][j + 1] == '@') counter++;
				if (map[i + 1][x - 1] == '@') counter++;
				if (map[i + 1][j] == '@') counter++;
				if (map[i + 1][j + 1] == '@') counter++;
			}
			//Правая грань
			if ((i != 0 && i != y - 1) && j == x - 1) {
				if (map[i - 1][j - 1] == '@') counter++;
				if (map[i - 1][j] == '@') counter++;
				if (map[i - 1][0] == '@') counter++;
				if (map[i][j - 1] == '@') counter++;
				if (map[i][0] == '@') counter++;
				if (map[i + 1][j - 1] == '@') counter++;
				if (map[i + 1][j] == '@') counter++;
				if (map[i + 1][0] == '@') counter++;
			}
			//Левый верхний угол
			if (i == 0 && j == 0) {
				if (map[y - 1][x - 1] == '@') counter++;
				if (map[y - 1][j] == '@') counter++;
				if (map[y - 1][j + 1] == '@') counter++;
				if (map[i][x - 1] == '@') counter++;
				if (map[i][j + 1] == '@') counter++;
				if (map[i + 1][x - 1] == '@') counter++;
				if (map[i + 1][j] == '@') counter++;
				if (map[i + 1][j + 1] == '@') counter++;
			}
			//правый верхний угол
			if (i == 0 && j == x - 1) {
				if (map[y - 1][j - 1] == '@') counter++;
				if (map[y - 1][j] == '@') counter++;
				if (map[y - 1][0] == '@') counter++;
				if (map[i][j - 1] == '@') counter++;
				if (map[i][0] == '@') counter++;
				if (map[i + 1][j - 1] == '@') counter++;
				if (map[i + 1][j] == '@') counter++;
				if (map[i + 1][0] == '@') counter++;
			}
			//Правый нижний угол
			if (i == y - 1 && j == x - 1) {
				if (map[i - 1][j - 1] == '@') counter++;
				if (map[i - 1][j] == '@') counter++;
				if (map[i - 1][0] == '@') counter++;
				if (map[i][j - 1] == '@') counter++;
				if (map[i][0] == '@') counter++;
				if (map[0][j - 1] == '@') counter++;
				if (map[0][j] == '@') counter++;
				if (map[0][0] == '@') counter++;
			}
			//Левый нижний угол
			if (i == y - 1 && j == 0) {
				if (map[i - 1][x - 1] == '@') counter++;
				if (map[i - 1][j] == '@') counter++;
				if (map[i - 1][j + 1] == '@') counter++;
				if (map[i][x - 1] == '@') counter++;
				if (map[i][j + 1] == '@') counter++;
				if (map[0][x - 1] == '@') counter++;
				if (map[0][j] == '@') counter++;
				if (map[0][j + 1] == '@') counter++;
			}

			//проверка окружения каждой клетки
			if (i > 0 && j > 0) {
				if ((i < y - 1) && (j < x - 1)) {
					for (int checkY = -1; checkY < 2; checkY++)
					{
						for (int checkX = -1; checkX < 2; checkX++)
						{
							if (checkY != 0 || checkX != 0) {
								if (map[i + checkY][j + checkX] == '@') counter++;
							}
						}
					}
				}
			}


			if (map[i][j] == ' ') {
				if (counter == 3) newMap[i][j] = '@';
			}
			else if (map[i][j] == '@') {
				if (counter == 2 || counter == 3) {
					newMap[i][j] = '@';
				}
				if (counter < 2 || counter > 3) {
					newMap[i][j] = ' ';
				}
			}
			counter = 0;
		}
	}
			
		
	
}

void Map::updateMap() {
	//Обновление карты
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{

			if (newMap[i][j] != 0) {
				map[i][j] = newMap[i][j];
				
			}
			/*cout << map[i][j] << ' ';*/
		}
		/*cout << endl;*/
	}
}

bool Map::printMap(int i, int j) {
	if (map[i][j] == '@') return true;
	else return false;
}

	
	
	
	


