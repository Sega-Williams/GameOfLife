#include <iostream>

using namespace std;
const int y = 40;
const int x = 40;

int main() {
	srand(time(0));
	int counter = 0;
	char map[y][x];
	char newMap[y][x];
	//Обнуление карты
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (rand() % 2 == 1) {
				map[i][j] = '@';
			}
			else map[i][j] = ' ';
			newMap[i][j] = 0;
		}
	}

	/*map[1][2] = '@';
	map[2][2] = '@';
	map[3][2] = '@';

	map[19][20] = '@';
	map[20][20] = '@';
	map[20][18] = '@';
	map[21][20] = '@';
	map[21][19] = '@';*/
	
	bool isLive = true;
	while (isLive) {
		system("cls");
		//Отрисовка карты
		for (int i = 0; i < y; i++)
		{
			for (int j = 0; j < x; j++)
			{
				cout << map[i][j] << ' ';
			}
			cout << endl;
		}
		//Обнуление карты следующей генерации
		for (int i = 0; i < y; i++)
		{
			for (int j = 0; j < x; j++)
			{
				newMap[i][j] = 0;
			}
		}
		//system("PAUSE");
		//Проверка карты
		for (int i = 0; i < y; i++)
		{
			for (int j = 0; j < x; j++)
			{
				//Верхняя грань
				if (i == 0 && (j !=0 && j != x-1)) {
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
				if (i > 0 && j > 0 || (i < y - 1) && (j < x - 1)) {
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
				
				
				if (map[i][j] == ' ') { 
					if (counter == 3) newMap[i][j] = '@'; 
				}
				else if (map[i][j] == '@') {
					if (counter == 2 || counter == 3) newMap[i][j] = '@';
					if (counter < 2 || counter > 3)  newMap[i][j] = ' ';
				}
				counter = 0;
			}
		}
		isLive = false;
		//Обновление карты
		for (int i = 0; i < y; i++)
		{
			for (int j = 0; j < x; j++)
			{
				
				if (newMap[i][j] != 0) {
					map[i][j] = newMap[i][j];
					isLive = true;
				}
				
			}
		}

	}
}