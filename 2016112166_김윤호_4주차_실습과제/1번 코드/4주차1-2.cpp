//2016112166 김윤호

#include <iostream>
#include <cstdlib>
#define Max 1000

using namespace std;

void FindMinMax(int A[], int n, int &Mini, int &Maxi)//참조 전달 형식으로 만들어서 함수에서 변한 값이 원래의 값도 변하도록 만들었습니다.
{
	Mini = A[0];
	Maxi = A[0];
	//비교하기 위해 제일 처음 값을 각각 넣어 주었습니다.
	int small, large;
	//반복문에서 2개씩 비교를 할 때 사용하기 위한 변수입니다.
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
		/*앞에서 비교 되지 않은 값 두개를 비교해서 
		큰 값은 large에 작은 값은 small에 넣어주었습니다*/
		if (small < Mini)
			Mini = small;
		if (large > Maxi)
			Maxi = large;
		/*small과 large에 있는 값들을 각각 mini와 maxi의 값과 비교를 해서
		각각 작은 값과 큰 값을 넣어 주었습니다.*/
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

	cout << "최소값 : " << Mini << endl;
	cout << "최대값 : " << Maxi << endl;
}
