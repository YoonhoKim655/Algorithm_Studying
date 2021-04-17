//2016112166 김윤호

#include <iostream>
#define MAX_SIZE 10
using namespace std;

void makeheap(int A[], int root, int LastNode)
{
	int P, L_Son, R_Son, Son, Root_Value;

	P = root;
	Root_Value = A[root];
	L_Son = 2 * P + 1;
	R_Son = L_Son + 1;

	while (L_Son <= LastNode)
	{
		if (R_Son <= LastNode && A[L_Son] < A[R_Son])
			Son = R_Son;//child 중 큰것올 골라 son에 넣음
		else 
			Son = L_Son;
		if (Root_Value < A[Son])// 루트값보다 son값이 크면
		{
			A[P] = A[Son];//son을 위로 올림
			P = Son;//son 이 parent 가 됨
			L_Son = P * 2 + 1;//child 다시 지정
			R_Son = L_Son + 1;
		}
		else
			break;
	}
	A[P] = Root_Value;
}

void HeapSort(int A[], int n)
{/* 입력: A[0:n－1], n - 정렬할 원소의 개수 출력: A[0:n－1] - 정렬된 배열. */
	int i;
	for (i = n / 2; i >= 0; i--)
		makeheap(A, i, n-1);
	for (i = n-1; i > 0; i--) 
	{
		int temp = A[0];
		A[0] = A[i];
		A[i] = temp;
		//힙의 최대값을 제거하고 (A[i]와 교환)
		makeheap(A, 0, i-1);
	}//남은 원소로 다시 힙재정비
}

void main()
{
	int A[MAX_SIZE] = { 4,1,3,2,16,9,10,14,8,7 };
	/*for (int i = MAX_SIZE / 2; i >= 0; i--)
	{
		makeheap(A, i, MAX_SIZE - 1);
	}*/
	/*cout << "생성된 힙 : " << endl;
	for (int i = MAX_SIZE / 2; i >= 0; i--)
		makeheap(A, i, MAX_SIZE - 1);*/
	cout << "정렬된 힙 : " << endl;
	HeapSort(A, MAX_SIZE);
	for (int i = 0; i < MAX_SIZE; i++)
	{
		cout << A[i]<<"	";
	}
	cout << endl;
}



