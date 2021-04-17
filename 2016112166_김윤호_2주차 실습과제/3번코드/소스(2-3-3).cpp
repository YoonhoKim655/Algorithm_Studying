//2016112166 ����ȣ

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
	stack<int> sta;//������ �ϱ� ���� ������ ���� ���� �ϱ� ���ؼ� stack�� ��������ϴ�.
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
		sta.pop();			//���� �ϱ� ���� ������ ���� ������ �� ������ ���߽��ϴ�. 
		if (end > start)
		{
			p = A[end];		//quicksort�� ���ذ��� ���߽��ϴ�.
			L = start - 1; //�Ʒ� while���� ���� �ϱ� ���ؼ� start�� -1�� �߽��ϴ�.
			R = end;
			while (1)
			{
				while (A[++L] < p);
				while (A[--R] > p);		// ���� ���ذ����� ũ��, ���� ���� ������ �� �ݺ��� ���߾����ϴ�.
				if (L >= R)
					break;	// ���ʺ��� ������ index�� ������ ���� ������ �ͺ��� ũ�ٸ� �ݺ��� ���߾����ϴ�.
				temp = A[L];
				A[L] = A[R];
				A[R] = temp;//���ʺ��� �����Ѱ��� �۾Ҵٸ� ������ index�� ���� �ٲ�����ϴ�.
			}

			temp = A[L];
			A[L] = A[end];
			A[end] = temp;//���ذ��� ������ �� ��ġ�� �־��־����ϴ�.
			sta.push(end);
			sta.push(L + 1);
			sta.push(L - 1);
			sta.push(start);//���� quicksort�� ���� �迭�� ��ġ�� stack�� �־��־����ϴ�.
		}
	}
}

void main()
{
	int N[MAX_N] = {};
	int K[MAX_K] = {};

	srand((unsigned int)time(0));

	cout << "���� �Ǳ� ���� �迭 : " << endl;
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