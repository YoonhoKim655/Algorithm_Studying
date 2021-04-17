//2016112166 ����ȣ

#include <iostream>
#define MAX_SIZE 10
using namespace std;

void merge(int list[], int left, int mid, int right) 
{
	int i, j, k = left, l;

	int sorted[MAX_SIZE];
	
	for (i = left, j = mid + 1 ; i <= mid && j <= right; )
	{
		sorted[k++] = (list[i] <= list[j]) ? list[i++] : list[j++];//list[i]�� list[j]�� ���ؼ� �� ���� ���� index�� 1�� ���߽��ϴ�. �� ������ ������ ���� ���� left�� ������ �Ǹ鼭 mid���� �ݺ��� �߽��ϴ�.
	}//���� ���ĵ� list
	
	if (i > mid)
		for (l = j; l <= right; l++, k++)
		{
			sorted[k] = list[l];
		}
	else
		for (l = i; l <= mid; l++, k++) {
			sorted[k] = list[l];
		}
	//���ʿ� ���� �ִ� �迭���� ���� ���־����ϴ�.

	for (l = left; l <= right; l++) {
		list[l] = sorted[l];
	}//�迭 sorted[] �� ����Ʈ�� �迭 list�� �纹�縦 �߽��ϴ�.
	for (int i = 0; i < MAX_SIZE; i++)//�ܰ躰�� ����� ���ؼ� merge�� �� ������ ����� �����ϴ�.
		cout << "|" << list[i] << "|";
	cout << endl;
}//���� �ڵ�

void merge_sort(int list[], int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;//������ �ִ� �迭���� ���� �κ��� ���߽��ϴ�.
		merge_sort(list,left, mid);//������ �κ��� ���� ���� ���������ϴ�.
		merge_sort(list, mid + 1, right);//��� �κ����� ������ ������ �������� ���������ϴ�.
		merge(list, left, mid, right);//�׸��� �ٽ� �������� ������ ������ ������ �ϴ� �ڵ��Դϴ�.
	}
}

void main()
{
	int A[MAX_SIZE] = { 30,20,40,35,5,50,45,10,25,15 };

	for (int i = 0; i < MAX_SIZE; i++)
		cout << "|" << A[i] << "|";
	cout << endl;
	merge_sort(A, 0, MAX_SIZE-1);
}