//2016112166 김윤호

#include <iostream>

using namespace std;

int cal_coin(int M, int c[], int d,int(&X)[11])//X라는 배열을 참조해서 각 M마다의 최소 coin수를 저장을 할 것입니다.
{
	if (M == 0) {
		return 0;
	}
		int e_coin = INT_MAX;
		/*각 money의 최소 코인 수를 하기 전에 int형이 가질 수 있는 최대의 값으로 설정을 해서
		  recursive로 여러번 반복을 해서 값을 최소의 값으로 만들 수 있게 했습니다.*/
	for (int i = 0; i < d; i++)
	{
		if (M >= c[i])
		{
			int temp = cal_coin(M - c[i], c, d, X);
			/*pdf에 나온 방식을 사용을 해서 구현을 했습니다.재귀 방식을 사용을 해서 
			  M에서 사용 할 수 있는 coin을 뺸 값들을 다시 coin으로 빼서 최선의 경우의 수를 찾는 방식입니다.*/
			if (temp != INT_MAX && temp + 1 < e_coin)
				e_coin = temp + 1; 
			/*재귀를 통해서 반복이 되면서 각 M이 가질 수 있는 최소의 수를 찾기 위해서 
			temp + 1이 기존의 e_coin보다 작을 때 e_coin의 값을 변경 했습니다.*/
		}/*e_coin의 값을 최소의 값으로 설정을 했습니다.*/ 
	}
	X[M-1] = e_coin;//배열의 각 M의 최소 coin수를 저장을 했습니다.
	return e_coin;
}


void main()
{
	int money = 11;
	int coin[] = { 1,4,7 };
	int d = sizeof(coin) / sizeof(int);
	int Min_coin[11];//가장 작은 coin의 수를 저장하기 위한 배열입니다.
	cal_coin(money, coin, d, Min_coin);
	for (int i = 0; i < 11; i++)
	{
		cout << "M : " << i+1 << " coin : " << Min_coin[i] << endl;
	}
}