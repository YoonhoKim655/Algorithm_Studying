//2016112166 김윤호

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
		/*가장 작은 값을 찾기 위해서 배열에 저장된 값을 모두 비교하면서
		가장 작은 값을 temp에 저장을 했습니다.*/
	}
	return temp;
	//저장된 가장 작은 값을 반환 했습니다.
}

int Maximum(int A[], int n)
{
	int i, temp;

	temp = A[0];
	for (i = 1; i < n; i++)
	{
		if (temp < A[i])
			temp = A[i];
		/*가장 큰 값을 찾기 위해서 배열에 저장된 값을 모두 비교하면서
		가장 큰 값을 temp에 저장을 했습니다.*/
	}
	return temp;
	//저장된 가장 큰 값을 반환 했습니다.
}

void main()
{
	int A[Max];
	
	for (int i = 0; i < Max; i++)
	{
		A[i] = rand() % 100000 + 1;
	}

	cout << "최소값 : " << Minimum(A, Max)<<endl;
	cout << "최대값 : " << Maximum(A, Max) << endl;
}
