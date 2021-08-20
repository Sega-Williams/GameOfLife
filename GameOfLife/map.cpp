#include "map.h"
Map::Map() {
	/*cout << "Create" << this << endl;*/
	map = new bool* [y];
	for (int i = 0; i < y; i++) map[i] = new bool[x];
	newMap = new bool* [y];
	for (int i = 0; i < y; i++) newMap[i] = new bool[x];
	
	//Generator
	for (int i = 0; i < y; i++){
		for (int j = 0; j < x; j++)
		{
			if (rand() % 2 == 1) map[i][j] = 1;
			else map[i][j] = 0;
			newMap[i][j] = 0;
		}
	}
}

Map::~Map() {
	/*cout << "Delete" << this << endl;*/
}

void Map::checkMap() {
	//Проверка карты
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			//Верхняя грань
			if (i == 0 && (j != 0 && j != x - 1)) {
				if (map[y - 1][j - 1] ) counter++;
				if (map[y - 1][j] ) counter++;
				if (map[y - 1][j + 1] ) counter++;
				if (map[i][j - 1] ) counter++;
				if (map[i][j + 1] ) counter++;
				if (map[i + 1][j - 1] ) counter++;
				if (map[i + 1][j] ) counter++;
				if (map[i + 1][j + 1] ) counter++;
			}
			//Нижняя грань
			if (i == y - 1 && (j != 0 && j != x - 1)) {
				if (map[i - 1][j - 1] ) counter++;
				if (map[i - 1][j] ) counter++;
				if (map[i - 1][j + 1] ) counter++;
				if (map[i][j - 1] ) counter++;
				if (map[i][j + 1] ) counter++;
				if (map[0][j - 1] ) counter++;
				if (map[0][j] ) counter++;
				if (map[0][j + 1] ) counter++;
			}
			//Левая грань
			if ((i != 0 && i != y - 1) && j == 0) {
				if (map[i - 1][x - 1] ) counter++;
				if (map[i - 1][j] ) counter++;
				if (map[i - 1][j + 1] ) counter++;
				if (map[i][x - 1] ) counter++;
				if (map[i][j + 1] ) counter++;
				if (map[i + 1][x - 1] ) counter++;
				if (map[i + 1][j] ) counter++;
				if (map[i + 1][j + 1] ) counter++;
			}
			//Правая грань
			if ((i != 0 && i != y - 1) && j == x - 1) {
				if (map[i - 1][j - 1] ) counter++;
				if (map[i - 1][j] ) counter++;
				if (map[i - 1][0] ) counter++;
				if (map[i][j - 1] ) counter++;
				if (map[i][0] ) counter++;
				if (map[i + 1][j - 1] ) counter++;
				if (map[i + 1][j] ) counter++;
				if (map[i + 1][0] ) counter++;
			}
			//Левый верхний угол
			if (i == 0 && j == 0) {
				if (map[y - 1][x - 1] ) counter++;
				if (map[y - 1][j] ) counter++;
				if (map[y - 1][j + 1] ) counter++;
				if (map[i][x - 1] ) counter++;
				if (map[i][j + 1] ) counter++;
				if (map[i + 1][x - 1] ) counter++;
				if (map[i + 1][j] ) counter++;
				if (map[i + 1][j + 1] ) counter++;
			}
			//правый верхний угол
			if (i == 0 && j == x - 1) {
				if (map[y - 1][j - 1] ) counter++;
				if (map[y - 1][j] ) counter++;
				if (map[y - 1][0] ) counter++;
				if (map[i][j - 1] ) counter++;
				if (map[i][0] ) counter++;
				if (map[i + 1][j - 1] ) counter++;
				if (map[i + 1][j] ) counter++;
				if (map[i + 1][0] ) counter++;
			}
			//Правый нижний угол
			if (i == y - 1 && j == x - 1) {
				if (map[i - 1][j - 1] ) counter++;
				if (map[i - 1][j] ) counter++;
				if (map[i - 1][0] ) counter++;
				if (map[i][j - 1] ) counter++;
				if (map[i][0] ) counter++;
				if (map[0][j - 1] ) counter++;
				if (map[0][j] ) counter++;
				if (map[0][0] ) counter++;
			}
			//Левый нижний угол
			if (i == y - 1 && j == 0) {
				if (map[i - 1][x - 1]) counter++;
				if (map[i - 1][j] ) counter++;
				if (map[i - 1][j + 1] ) counter++;
				if (map[i][x - 1] ) counter++;
				if (map[i][j + 1] ) counter++;
				if (map[0][x - 1] ) counter++;
				if (map[0][j] ) counter++;
				if (map[0][j + 1] ) counter++;
			}

			//проверка окружения каждой клетки
			if (i > 0 && j > 0) {
				if ((i < y - 1) && (j < x - 1)) {
					for (int checkY = -1; checkY < 2; checkY++)
					{
						for (int checkX = -1; checkX < 2; checkX++)
						{
							if (checkY != 0 || checkX != 0) {
								if (map[i + checkY][j + checkX]) counter++;
							}
						}
					}
				}
			}

			if (map[i][j]) {
				if (counter == 2 || counter == 3) {
					newMap[i][j] = 1;
				}
				if (counter < 2 || counter > 3) {
					newMap[i][j] = 0;
				}
			}
			else if (counter == 3) newMap[i][j] = 1;
			
			counter = 0;
		}
	}
	//Обновление карты
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			map[i][j] = newMap[i][j];

			//обнуление nextGen
			newMap[i][j] = 0;
		}
	}	
}



	
	
	
	


