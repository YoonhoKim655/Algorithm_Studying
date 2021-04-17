//2016112166 ����ȣ	

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <time.h>
#define MAX_N 10
#define MAX_K 1000
using namespace std;

void Bubble(int X[], int n)
{
	if (n == 1)
		return; //�迭�� ����Ǿ��ִ� ���� �ϳ� �� ���, �ƹ��͵� ���� �ʾҽ��ϴ�.
	int temp = 0;
	for (int j = 1; j < n; j++)
	{
		if (X[j - 1] > X[j])
		{
			temp = X[j];
			X[j] = X[j - 1];
			X[j - 1] = temp;
		}//j�� �ִ� ������ �տ� �ִ� ���� �� ũ�ٸ� �� ���� ���� �ٲپ� �־����ϴ�.
	}	//���� ������� n��°�� ���� ���� �� ������ �־��־����ϴ�.
	Bubble(X, n - 1);//��� ������� �迭�� ������ �߽��ϴ�.
}

void main()
{
	int N[MAX_N] = {};
	int K[MAX_K] = {};
	
	srand((unsigned int)time(0));//srand�Լ��� ����� �ؼ� ���� �� ���� �ٸ� ������ ������ �ϰ� �߽��ϴ�.

	cout << "���� ���� �迭 : " << endl;
	for (int i = 0; i < MAX_N; i++)
	{
		N[i] = rand() % 10000 + 1;//1~10000������ ������ ������ �ؼ� N�� ������ �߽��ϴ�.
		cout << N[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < MAX_K; i++)
	{
		K[i] = rand() % 10000 + 1;
	}
	Bubble(N, MAX_N);
	cout << "���� ���� �迭 : " << endl;
	for (int i = 0; i < MAX_N; i++)
	{
		cout << N[i] << " ";
	}
	
}
