//2016112166 ����ȣ

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
	cout << "�� ���� �Է� : ";
	cin >> a >> b;
	cout << "�� ���� �ִ� ������� : " << gcd(a, b) << endl;
}