//2016112166 ����ȣ

#include <iostream>

#define MAX_SIZE 10
using namespace std;

void merge_sort(int list[])
{
	int mid, right;
	int a, b, x;

	int sorted[MAX_SIZE];//���ĵ� �迭�� ������ �ϱ� ���� �迭

	for (int k = 1; k < MAX_SIZE; k *= 2) //k�� ���� �Ǵ� ��ġ�� �����ִ� ���Դϴ�. �ݺ��� ���ؼ� �ٽ� �տ��� ���� ������ �� �� �ְ� ���ݴϴ�.
	{
		for (int left = 0; left + k < MAX_SIZE; left += k * 2) 
		{
			mid = left + k;
			right = mid + k;
			//mid�� right�� ���� ������ �߽��ϴ�.
			if (right > MAX_SIZE) right = MAX_SIZE;
			x = left; a = left; b = mid;
			while (a < mid && b < right)//�̿� ���� ������ �������� while���� ����� �ؼ� 
			{
				sorted[x++] = (list[a] <= list[b]) ? list[a++] : list[b++];
			}//��� �κа� ���� ������� ������ �߰� �� ���� ���ο� �迭�� �־����ϴ�.
			while (a < mid) 
			{
				sorted[x++] = list[a++];
			}
			while (b < right) 
			{
				sorted[x++] = list[b++];
			}
			for (x = left; x < right; x++)
			{
				list[x] = sorted[x];
			}//���ĵ� �迭�� �ٽ� ������ ������ �����ϴ� �迭�� ������ �߽��ϴ�.
			for(int i = 0; i < MAX_SIZE;i++)
				cout << "|" << list[i] << "|";
			cout << endl;
		}
	}
}

void main()
{
	
		int A[MAX_SIZE] = { 30,20,40,35,5,50,45,10,25,15 };

		merge_sort(A);
	
}