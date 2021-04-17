//2016112166 김윤호

#include <iostream>
using namespace std;

int gcd(int x, int y)
{
	int temp;
	while (y != 0)
	{
		temp = x % y;
		x = y;
		y = temp;
	}//y가 0일 될 때까지 x를 y로 나눈 나머지를 구해서 x의 값을 y의 값으로 바꿔주고 y는 그 나머지 값으로 바꿔줘서 최대공약수를 구하는 방법을 사용을 했습니다.
	return x;
}

void main()
{
	int a, b;
	cout << "두 숫자 입력 : ";
	cin >> a >> b;
	cout <<"두 수의 최대 공약수는 : " << gcd(a, b) << endl;
}