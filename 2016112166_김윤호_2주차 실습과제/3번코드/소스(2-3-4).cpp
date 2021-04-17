//2016112166 ����ȣ

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
	//clock()�Լ��� ��ȯ���� clock_t�� ������ ������ ������ �����ؼ� ���۽ð��� ������ �ð��� ������ �� �� �ְ� �߽��ϴ�.
	
	double result;

	start_Q = clock();// �Լ��� ���� �ð��� ������ �߽��ϴ�.

	quickSort(K_Q, MAX_K);
	
	end_Q = clock();//�Լ��� ������ �ð��� ������ �߽��ϴ�.

	result = (double)(end_Q - start_Q);//�Լ��� ���� �ð��� ����� �� �ð��� ���� �ð��� ���� �˴ϴ�.

	cout << "Quick result : " << ((result) / CLOCKS_PER_SEC) << " seconds" << endl; // CLOCKS_PER_SEC�� �ð� ������ ǥ���ϱ� ���ؼ� ����� �߽��ϴ�.




	start = clock();

	Bubble(K, MAX_K);
	
	end = clock();
	result = (double)(end - start);

	cout << "Bubule result : " << ((result) / CLOCKS_PER_SEC) << "seconds" << endl;

}
