//2016112166 ����ȣ

#include <iostream>
#include <cstdlib>
#define Max 1000

using namespace std;
int Minimum(int A[], int n)
{
	int i, temp;

	temp = A[0];
	for (i = 1; i < n; i++)
	{
		if (temp > A[i])
			temp = A[i];
		/*���� ���� ���� ã�� ���ؼ� �迭�� ����� ���� ��� ���ϸ鼭
		���� ���� ���� temp�� ������ �߽��ϴ�.*/
	}
	return temp;
	//����� ���� ���� ���� ��ȯ �߽��ϴ�.
}

int Maximum(int A[], int n)
{
	int i, temp;

	temp = A[0];
	for (i = 1; i < n; i++)
	{
		if (temp < A[i])
			temp = A[i];
		/*���� ū ���� ã�� ���ؼ� �迭�� ����� ���� ��� ���ϸ鼭
		���� ū ���� temp�� ������ �߽��ϴ�.*/
	}
	return temp;
	//����� ���� ū ���� ��ȯ �߽��ϴ�.
}

void main()
{
	int A[Max];
	
	for (int i = 0; i < Max; i++)
	{
		A[i] = rand() % 100000 + 1;
	}

	cout << "�ּҰ� : " << Minimum(A, Max)<<endl;
	cout << "�ִ밪 : " << Maximum(A, Max) << endl;
}
