//2016112166 김윤호

#include <iostream>
using namespace std;

struct Map
{
	int right, down;
};/*Map의 변수를 right와 down으로  각자가 가진 
  관광지의 수를 가지는 변수로 만들었습니다.*/
void Findpath(struct Map map[5][5], int D_f, int D_s)
{
	int path[5][5] = { 0 ,};
	/*어느 방향으로 이동을 했는지를 알기위한 값을 저장을 했습니다.
	오른쪽으로 이동시 1, 아래는 2를 저장을 했습니다.*/
	int S_f = 0, S_s = 0;//시작점
	cout << "경로 : ";
	while (S_f != D_f || S_s != D_s)
	{
		cout << "map[" << S_f << "][" << S_s << "]"<<",";
		//지나간 경로를 표시하기 위해서 반복문 안에서 변화하는 좌표를 넣었습니다.
		if (map[S_f][S_s].right > map[S_f][S_s].down)//오른쪽으로 부여된 값이 더 큰 경우
		{
			if (S_s < D_s)
			{
				path[S_f][S_s] = 1;
				S_s++;
			}
			else
			{
				path[S_f][S_s] = 2;
				S_f++;
			}
		}
		/*row값이 도착점의 row값보다 작을 경우 해당 좌표의 path를 1로 저장을 하고
		 row값을 +1을 해주었고 해당 row값이 도착점보다 작지 않을 경우path를 2로 
		 저장을 하고 column값을 올렸습니다.*/
		else//아래로 부여된 값이 더 클 경우
		{
			if (S_f < D_f)
			{
				path[S_f][S_s] = 2;
				S_f++;
			}
			else
			{
				path[S_f][S_s] = 1;
				S_s++;
			}
		}
		/*column값이 도착점의 column값보다 작을 경우 해당 좌표의 path를 2로 저장을 하고
		 column값을 +1을 해주었고 해당 column값이 도착점보다 작지 않을 경우 path를 1로
		 저장을 하고 row값을 올렸습니다.*/
	}
	cout << "map[" << D_f << "][" << D_s << "]" << endl;
	cout << endl;
	int i, j;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if(path[i][j] == 1)
				cout << "map[" << i << "][" << j << "]" << "-";
			else
				cout << "map[" << i << "][" << j << "]" << " ";
		}
		cout << endl;
		for (j = 0; j < 5; j++)
		{
			if (path[i][j] == 2)
			{
				cout << "    |    ";
			}
			else
			{
				cout << "          ";
			}
		}
		cout << endl;
	}//맵의 경로를 그리기 위해 각 path들의 값을 따라서 그렸습니다.
}

void main()
{
	struct Map map[5][5];
	map[0][0].right = 3; map[0][0].down = 1;
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
	Findpath(map, 3, 4);

	
}