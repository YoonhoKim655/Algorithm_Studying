//2016112166 김윤호

#include <iostream>
using namespace std;

int gcd(int x, int y)
{
	if (y == 0)
		return x;
	else
		return gcd(y, x%y);
}

void main()
{
	int a, b;
	cout << "두 숫자 입력 : ";
	cin >> a >> b;
	cout << "두 수의 최대 공약수는 : " << gcd(a, b) << endl;
}