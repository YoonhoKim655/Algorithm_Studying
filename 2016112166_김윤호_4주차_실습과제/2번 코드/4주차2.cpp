//2016112166 ����ȣ

#include <iostream>
using namespace std;

struct Map
{
	int right, down;
};/*Map�� ������ right�� down����  ���ڰ� ���� 
  �������� ���� ������ ������ ��������ϴ�.*/
void Findpath(struct Map map[5][5], int D_f, int D_s)
{
	int path[5][5] = { 0 ,};
	/*��� �������� �̵��� �ߴ����� �˱����� ���� ������ �߽��ϴ�.
	���������� �̵��� 1, �Ʒ��� 2�� ������ �߽��ϴ�.*/
	int S_f = 0, S_s = 0;//������
	cout << "��� : ";
	while (S_f != D_f || S_s != D_s)
	{
		cout << "map[" << S_f << "][" << S_s << "]"<<",";
		//������ ��θ� ǥ���ϱ� ���ؼ� �ݺ��� �ȿ��� ��ȭ�ϴ� ��ǥ�� �־����ϴ�.
		if (map[S_f][S_s].right > map[S_f][S_s].down)//���������� �ο��� ���� �� ū ���
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
		/*row���� �������� row������ ���� ��� �ش� ��ǥ�� path�� 1�� ������ �ϰ�
		 row���� +1�� ���־��� �ش� row���� ���������� ���� ���� ���path�� 2�� 
		 ������ �ϰ� column���� �÷Ƚ��ϴ�.*/
		else//�Ʒ��� �ο��� ���� �� Ŭ ���
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
		/*column���� �������� column������ ���� ��� �ش� ��ǥ�� path�� 2�� ������ �ϰ�
		 column���� +1�� ���־��� �ش� column���� ���������� ���� ���� ��� path�� 1��
		 ������ �ϰ� row���� �÷Ƚ��ϴ�.*/
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
	}//���� ��θ� �׸��� ���� �� path���� ���� ���� �׷Ƚ��ϴ�.
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
	//map�� ����� ����ġ�� ������ �߽��ϴ�.
	Findpath(map, 3, 4);

	
}