//2016112166 김윤호

#include <iostream>
#include <cstdlib>
#include <stack>
#include <algorithm>
#include <ctime>

#define MAX_N 10
#define MAX_K 1000
using namespace std;

void quick(int A[], int num)
{
	stack<int> sta;//정렬을 하기 위한 범위의 값을 저장 하기 위해서 stack을 만들었습니다.
	int p, temp;
	int L, R;
	int start=0, end=num-1;

	sta.push(end);
	sta.push(start);
	while (!sta.empty())
	{
		start = sta.top();
		sta.pop();
		end = sta.top();
		sta.pop();			//정렬 하기 위해 정렬의 시작 지점과 끝 지점을 정했습니다. 
		if (end > start)
		{
			p = A[end];		//quicksort의 기준값을 정했습니다.
			L = start - 1; //아래 while문을 쉽게 하기 위해서 start에 -1을 했습니다.
			R = end;
			while (1)
			{
				while (A[++L] < p);
				while (A[--R] > p);		// 각각 기준값보다 크고, 작은 것을 만났을 때 반복을 멈추었습니다.
				if (L >= R)
					break;	// 왼쪽부터 시작한 index가 오른쪽 부터 시작한 것보다 크다면 반복을 멈추었습니다.
				temp = A[L];
				A[L] = A[R];
				A[R] = temp;//왼쪽부터 시작한것이 작았다면 각각의 index의 값을 바꿔줬습니다.
			}

			temp = A[L];
			A[L] = A[end];
			A[end] = temp;//기준값을 정렬이 된 위치에 넣어주었습니다.
			sta.push(end);
			sta.push(L + 1);
			sta.push(L - 1);
			sta.push(start);//다음 quicksort를 위한 배열의 위치를 stack에 넣어주었습니다.
		}
	}
}

void main()
{
	int N[MAX_N] = {};
	int K[MAX_K] = {};

	srand((unsigned int)time(0));

	cout << "정렬 되기 전의 배열 : " << endl;
	for (int i = 0; i < MAX_N; i++)
	{
		N[i] = rand() % 10000 + 1;
		cout << N[i] << "	";
	}
	cout << endl;
	
	for (int i = 0; i < MAX_K; i++)
	{
		K[i] = rand() % 10000 + 1;
	}
	quick(N,MAX_N);
	cout << "Sorted N" << endl;
	for (int i = 0; i < MAX_N; i++)
	{
		cout << N[i] << "	";
	}
	
}