//2016112166 김윤호	

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
		return; //배열에 저장되어있는 값이 하나 일 경우, 아무것도 하지 않았습니다.
	int temp = 0;
	for (int j = 1; j < n; j++)
	{
		if (X[j - 1] > X[j])
		{
			temp = X[j];
			X[j] = X[j - 1];
			X[j - 1] = temp;
		}//j에 있는 수보다 앞에 있는 수가 더 크다면 두 수의 값을 바꾸어 주었습니다.
	}	//위에 방식으로 n번째에 수를 정렬 된 값으로 넣어주었습니다.
	Bubble(X, n - 1);//재귀 방식으로 배열을 정렬을 했습니다.
}

void main()
{
	int N[MAX_N] = {};
	int K[MAX_K] = {};
	
	srand((unsigned int)time(0));//srand함수를 사용을 해서 실행 시 마다 다른 난수를 생성을 하게 했습니다.

	cout << "정렬 전의 배열 : " << endl;
	for (int i = 0; i < MAX_N; i++)
	{
		N[i] = rand() % 10000 + 1;//1~10000까지의 난수를 생성을 해서 N에 저장을 했습니다.
		cout << N[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < MAX_K; i++)
	{
		K[i] = rand() % 10000 + 1;
	}
	Bubble(N, MAX_N);
	cout << "정렬 후의 배열 : " << endl;
	for (int i = 0; i < MAX_N; i++)
	{
		cout << N[i] << " ";
	}
	
}
