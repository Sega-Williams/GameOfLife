#include "map.h"
Map::Map() {
	
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
	/*for (int i = 0; i < y; i++){
		for (int j = 0; j < x; j++)
		{
			map[i][j] = 0;
			newMap[i][j] = 0;
		}
	}
	map[1][2] = 1;
	map[2][2] = 1;
	map[3][2] = 1;
	map[19][20] = 1;
	map[20][20] = 1;
	map[20][18] = 1;
	map[21][20] = 1;
	map[21][19] = 1;*/
}

void Map::checkMap() {
	//�������� �����
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			//������� �����
			if (i == 0 && (j != 0 && j != x - 1)) {
				if (map[y - 1][j - 1] == 1) counter++;
				if (map[y - 1][j] == 1) counter++;
				if (map[y - 1][j + 1] == 1) counter++;
				if (map[i][j - 1] == 1) counter++;
				if (map[i][j + 1] == 1) counter++;
				if (map[i + 1][j - 1] == 1) counter++;
				if (map[i + 1][j] == 1) counter++;
				if (map[i + 1][j + 1] == 1) counter++;
			}
			//������ �����
			if (i == y - 1 && (j != 0 && j != x - 1)) {
				if (map[i - 1][j - 1] == 1) counter++;
				if (map[i - 1][j] == 1) counter++;
				if (map[i - 1][j + 1] == 1) counter++;
				if (map[i][j - 1] == 1) counter++;
				if (map[i][j + 1] == 1) counter++;
				if (map[0][j - 1] == 1) counter++;
				if (map[0][j] == 1) counter++;
				if (map[0][j + 1] == 1) counter++;
			}
			//����� �����
			if ((i != 0 && i != y - 1) && j == 0) {
				if (map[i - 1][x - 1] == 1) counter++;
				if (map[i - 1][j] == 1) counter++;
				if (map[i - 1][j + 1] == 1) counter++;
				if (map[i][x - 1] == 1) counter++;
				if (map[i][j + 1] == 1) counter++;
				if (map[i + 1][x - 1] == 1) counter++;
				if (map[i + 1][j] == 1) counter++;
				if (map[i + 1][j + 1] == 1) counter++;
			}
			//������ �����
			if ((i != 0 && i != y - 1) && j == x - 1) {
				if (map[i - 1][j - 1] == 1) counter++;
				if (map[i - 1][j] == 1) counter++;
				if (map[i - 1][0] == 1) counter++;
				if (map[i][j - 1] == 1) counter++;
				if (map[i][0] == 1) counter++;
				if (map[i + 1][j - 1] == 1) counter++;
				if (map[i + 1][j] == 1) counter++;
				if (map[i + 1][0] == 1) counter++;
			}
			//����� ������� ����
			if (i == 0 && j == 0) {
				if (map[y - 1][x - 1] == 1) counter++;
				if (map[y - 1][j] == 1) counter++;
				if (map[y - 1][j + 1] == 1) counter++;
				if (map[i][x - 1] == 1) counter++;
				if (map[i][j + 1] == 1) counter++;
				if (map[i + 1][x - 1] == 1) counter++;
				if (map[i + 1][j] == 1) counter++;
				if (map[i + 1][j + 1] == 1) counter++;
			}
			//������ ������� ����
			if (i == 0 && j == x - 1) {
				if (map[y - 1][j - 1] == 1) counter++;
				if (map[y - 1][j] == 1) counter++;
				if (map[y - 1][0] == 1) counter++;
				if (map[i][j - 1] == 1) counter++;
				if (map[i][0] == 1) counter++;
				if (map[i + 1][j - 1] == 1) counter++;
				if (map[i + 1][j] == 1) counter++;
				if (map[i + 1][0] == 1) counter++;
			}
			//������ ������ ����
			if (i == y - 1 && j == x - 1) {
				if (map[i - 1][j - 1] == 1) counter++;
				if (map[i - 1][j] == 1) counter++;
				if (map[i - 1][0] == 1) counter++;
				if (map[i][j - 1] == 1) counter++;
				if (map[i][0] == 1) counter++;
				if (map[0][j - 1] == 1) counter++;
				if (map[0][j] == 1) counter++;
				if (map[0][0] == 1) counter++;
			}
			//����� ������ ����
			if (i == y - 1 && j == 0) {
				if (map[i - 1][x - 1] == 1) counter++;
				if (map[i - 1][j] == 1) counter++;
				if (map[i - 1][j + 1] == 1) counter++;
				if (map[i][x - 1] == 1) counter++;
				if (map[i][j + 1] == 1) counter++;
				if (map[0][x - 1] == 1) counter++;
				if (map[0][j] == 1) counter++;
				if (map[0][j + 1] == 1) counter++;
			}

			//�������� ��������� ������ ������
			if (i > 0 && j > 0) {
				if ((i < y - 1) && (j < x - 1)) {
					for (int checkY = -1; checkY < 2; checkY++)
					{
						for (int checkX = -1; checkX < 2; checkX++)
						{
							if (checkY != 0 || checkX != 0) {
								if (map[i + checkY][j + checkX] == 1) counter++;
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

	//���������� �����
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			map[i][j] = newMap[i][j];

			//��������� nextGen
			newMap[i][j] = 0;
		}
	}	
}




	
	
	
	


