//2016112166 ����ȣ

#include <iostream>
#include <cstdlib>
#define Max 1000

using namespace std;

void FindMinMax(int A[], int n, int &Mini, int &Maxi)//���� ���� �������� ���� �Լ����� ���� ���� ������ ���� ���ϵ��� ��������ϴ�.
{
	Mini = A[0];
	Maxi = A[0];
	//���ϱ� ���� ���� ó�� ���� ���� �־� �־����ϴ�.
	int small, large;
	//�ݺ������� 2���� �񱳸� �� �� ����ϱ� ���� �����Դϴ�.
	for (int i = 1; i < n - 1; i += 2)
	{
		if (A[i] < A[i + 1])
		{
			small = A[i];
			large = A[i + 1];
		}
		else
		{
			small = A[i + 1];
			large = A[i];
		}
		/*�տ��� �� ���� ���� �� �ΰ��� ���ؼ� 
		ū ���� large�� ���� ���� small�� �־��־����ϴ�*/
		if (small < Mini)
			Mini = small;
		if (large > Maxi)
			Maxi = large;
		/*small�� large�� �ִ� ������ ���� mini�� maxi�� ���� �񱳸� �ؼ�
		���� ���� ���� ū ���� �־� �־����ϴ�.*/
	}
}

void main()
{
	int Mini=0, Maxi=0;
	int A[Max];
	for (int i = 0; i < Max; i++)
	{
		A[i] = rand() % 100000 + 1;
	}

	FindMinMax(A, Max, Mini, Maxi);

	cout << "�ּҰ� : " << Mini << endl;
	cout << "�ִ밪 : " << Maxi << endl;
}
