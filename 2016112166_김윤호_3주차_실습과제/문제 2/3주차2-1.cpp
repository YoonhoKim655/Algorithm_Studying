//2016112166 ����ȣ

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
			Son = R_Son;//child �� ū�Ϳ� ��� son�� ����
		else 
			Son = L_Son;
		if (Root_Value < A[Son])// ��Ʈ������ son���� ũ��
		{
			A[P] = A[Son];//son�� ���� �ø�
			P = Son;//son �� parent �� ��
			L_Son = P * 2 + 1;//child �ٽ� ����
			R_Son = L_Son + 1;
		}
		else
			break;
	}
	A[P] = Root_Value;
}

void HeapSort(int A[], int n)
{/* �Է�: A[0:n��1], n - ������ ������ ���� ���: A[0:n��1] - ���ĵ� �迭. */
	int i;
	for (i = n / 2; i >= 0; i--)
		makeheap(A, i, n-1);
	for (i = n-1; i > 0; i--) 
	{
		int temp = A[0];
		A[0] = A[i];
		A[i] = temp;
		//���� �ִ밪�� �����ϰ� (A[i]�� ��ȯ)
		makeheap(A, 0, i-1);
	}//���� ���ҷ� �ٽ� ��������
}

void main()
{
	int A[MAX_SIZE] = { 4,1,3,2,16,9,10,14,8,7 };
	/*for (int i = MAX_SIZE / 2; i >= 0; i--)
	{
		makeheap(A, i, MAX_SIZE - 1);
	}*/
	/*cout << "������ �� : " << endl;
	for (int i = MAX_SIZE / 2; i >= 0; i--)
		makeheap(A, i, MAX_SIZE - 1);*/
	cout << "���ĵ� �� : " << endl;
	HeapSort(A, MAX_SIZE);
	for (int i = 0; i < MAX_SIZE; i++)
	{
		cout << A[i]<<"	";
	}
	cout << endl;
}



