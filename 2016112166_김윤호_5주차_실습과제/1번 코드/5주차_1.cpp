//2016112166 김윤호

#include <iostream>
using namespace std;

struct Map
{
	int right, down, state;
	bool R_path=false, D_path=false;
};/*Map의 변수를 right와 down, state 각 path를 만들어서 각자가 가진
  관광지의 수를 가지는 변수와 가중치 그리고 다음 경로가 어딘지 나타내는 변수를 만들었습니다.*/
void Findpath_1(struct Map map[5][5], int D_f, int D_s)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 1; j < 5; j++)
		{
			if (i == 0)
			{
				map[i][j].state=map[i][j-1].state+map[i][j-1].right;
				map[i][j - 1].R_path = true;
				map[j][i].state = map[j-1][i].state + map[j - 1][i].down;
				map[j - 1][i].D_path = true;
			}/*1행과 1열은 위와 같은 원리로 만들어지기에 따로 만들었습니다.*/
			else
			{
				map[i][j].state = (map[i][j - 1].state + map[i][j - 1].right - (map[i - 1][j].state + map[i - 1][j].down) > 0) ? map[i][j - 1].state + map[i][j - 1].right : map[i - 1][j].state + map[i - 1][j].down;
				if (map[i][j - 1].state + map[i][j - 1].right - (map[i - 1][j].state + map[i - 1][j].down) > 0)
					map[i][j - 1].R_path = true;
				else if (map[i][j - 1].state + map[i][j - 1].right - (map[i - 1][j].state + map[i - 1][j].down) < 0)
					map[i - 1][j].D_path = true;
				else
				{
					if (map[i][j - 1].state + map[i][j - 1].right - (map[i - 1][j].state + map[i - 1][j].down) == 0)
					{
						map[i][j - 1].R_path = true;
						map[i - 1][j].D_path = true;
					}
				}
				
				map[j][i].state = (map[j][i - 1].state + map[j][i - 1].right - (map[j - 1][i].state + map[j - 1][i].down) > 0) ? map[j][i - 1].state + map[j][i - 1].right : map[j - 1][i].state + map[j - 1][i].down;
				if (map[j][i - 1].state + map[j][i - 1].right - (map[j - 1][i].state + map[j - 1][i].down) > 0)
					map[j][i - 1].R_path = true;
				else if (map[j][i - 1].state + map[j][i - 1].right - (map[j - 1][i].state + map[j - 1][i].down) < 0)
					map[j - 1][i].D_path = true;
				else
				{
					if (map[j][i - 1].state + map[j][i - 1].right - (map[j - 1][i].state + map[j - 1][i].down) == 0)
					{
						map[j][i - 1].R_path = true;
						map[j - 1][i].D_path = true;
					}
				}
				/*1행과 1열을 제외한 다른 부분은 map의 왼쪽과 위부분의 state들과 각각 right, down 가중치를 더한 값을 비교해서 더 큰 값을 가지고,
				움직인 방향에 따라서 path의 값도 설정을 했습니다.*/
			}
		}
	}
	int i, j;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (map[i][j].R_path == true)
				cout << "map[" << i << "][" << j << "]" << "→";
			else
				cout << "map[" << i << "][" << j << "]" << " ";
		}
		cout << endl;
		for (j = 0; j < 5; j++)
		{
			if (map[i][j].D_path == true)
			{
				cout << "    ↓    ";
			}
			else
			{
				cout << "          ";
			}
		}
		cout << endl;
	}
	/*각 map에 저장된 path에 따라서 그림을 그렸습니다.*/
	
	cout << "각 위치의 값들이 가질 수 있는 최대의 값" << endl;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
				cout << map[i][j].state << " ";
		}
		cout << endl;
	}
}/*map의 위치에 맞춰서 state들을 출력을 해서 각 map이 가질 수 있는 가장 큰 값을 출력을 했습니다.*/

void main()
{
	struct Map map[5][5];
	map[0][0].right = 3; map[0][0].down = 1; map[0][0].state = 0;
	map[0][1].right = 2; map[0][1].down = 0;
	map[0][2].right = 4; map[0][2].down = 2;
	map[0][3].right = 0; map[0][3].down = 4;
	map[0][4].right = NULL; map[0][4].down = 3;

	map[1][0].right = 3; map[1][0].down = 4;
	map[1][1].right = 2; map[1][1].down = 6;
	map[1][2].right = 4; map[1][2].down = 5;
	map[1][3].right = 1; map[1][3].down = 2;
	map[1][4].right = NULL; map[1][4].down = 1;

	map[2][0].right = 0; map[2][0].down = 4;
	map[2][1].right = 7; map[2][1].down = 4;
	map[2][2].right = 3; map[2][2].down = 5;
	map[2][3].right = 4; map[2][3].down = 2;
	map[2][4].right = NULL; map[2][4].down = 1;

	map[3][0].right = 3; map[3][0].down = 5;
	map[3][1].right = 3; map[3][1].down = 6;
	map[3][2].right = 0; map[3][2].down = 8;
	map[3][3].right = 2; map[3][3].down = 5;
	map[3][4].right = NULL; map[3][4].down = 3;

	map[4][0].right = 1; map[4][0].down = NULL;
	map[4][1].right = 3; map[4][1].down = NULL;
	map[4][2].right = 2; map[4][2].down = NULL;
	map[4][3].right = 2; map[4][3].down = NULL;
	//map의 경로의 가중치를 설정을 했습니다.
	Findpath_1(map, 3, 2);


}