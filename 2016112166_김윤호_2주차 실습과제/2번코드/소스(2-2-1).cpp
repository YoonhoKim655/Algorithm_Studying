//2016112166 ����ȣ

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
	}//y�� 0�� �� ������ x�� y�� ���� �������� ���ؼ� x�� ���� y�� ������ �ٲ��ְ� y�� �� ������ ������ �ٲ��༭ �ִ������� ���ϴ� ����� ����� �߽��ϴ�.
	return x;
}

void main()
{
	int a, b;
	cout << "�� ���� �Է� : ";
	cin >> a >> b;
	cout <<"�� ���� �ִ� ������� : " << gcd(a, b) << endl;
}