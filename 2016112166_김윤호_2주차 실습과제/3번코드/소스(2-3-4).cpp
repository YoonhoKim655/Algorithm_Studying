//2016112166 김윤호

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <algorithm>
#include <time.h>
#define MAX_N 10
#define MAX_K 1000
using namespace std;


void quickSort(int A[], int num)
{
	stack<int> sta;
	int p, temp;
	int L, R;
	int start = 0, end = num - 1;

	sta.push(end);
	sta.push(start);
	while (!sta.empty())
	{
		start = sta.top();
		sta.pop();
		end = sta.top();
		sta.pop();
		if (end > start)
		{
			p = A[end];
			L = start - 1;
			R = end;
			while (1)
			{
				while (A[++L] < p);
				while (A[--R] > p);
				if (L >= R)
					break;
				temp = A[L];
				A[L] = A[R];
				A[R] = temp;
			}

			temp = A[L];
			A[L] = A[end];
			A[end] = temp;
			sta.push(end);
			sta.push(L + 1);
			sta.push(L - 1);
			sta.push(start);

		}
	}
}

void Bubble(int X[], int n)
{
	if (n == 1)
		return;
			
	int temp = 0;
	for (int j = 1; j < n; j++)
	{
		if (X[j - 1] > X[j])
		{
			temp = X[j];
			X[j] = X[j - 1];
			X[j - 1] = temp;
		}
	}
	Bubble(X, n - 1);
}

void main()
{
	int N[MAX_N] = {};
	int K[MAX_K] = {};
	int K_Q[MAX_K] = {};

	srand((unsigned int)time(0));

	for (int i = 0; i < MAX_K; i++)
	{
		K[i] = rand() % 10000 + 1;
		K_Q[i] = K[i];
	}
	clock_t start,start_Q, end,end_Q;
	//clock()함수의 반환형인 clock_t를 형으로 가지는 변수를 선언해서 시작시간과 끝나는 시간을 저장을 할 수 있게 했습니다.
	
	double result;

	start_Q = clock();// 함수의 시작 시간을 저장을 했습니다.

	quickSort(K_Q, MAX_K);
	
	end_Q = clock();//함수가 끝나는 시간을 저장을 했습니다.

	result = (double)(end_Q - start_Q);//함수의 실행 시간은 저장된 끝 시간과 시작 시간의 차가 됩니다.

	cout << "Quick result : " << ((result) / CLOCKS_PER_SEC) << " seconds" << endl; // CLOCKS_PER_SEC는 시간 단위를 표현하기 위해서 사용을 했습니다.




	start = clock();

	Bubble(K, MAX_K);
	
	end = clock();
	result = (double)(end - start);

	cout << "Bubule result : " << ((result) / CLOCKS_PER_SEC) << "seconds" << endl;

}
