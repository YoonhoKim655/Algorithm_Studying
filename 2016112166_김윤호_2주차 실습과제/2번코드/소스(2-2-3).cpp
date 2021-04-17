//2016112166 ����ȣ

#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define MAX_NUM 256

int gcd(int x, int y)
{
	int temp;
	while (y != 0)
	{
		temp = x % y;
		x = y;
		y = temp;
	}
	return x;
}

int N_gcd(int num[MAX_NUM])
{
	int GCD;
	int num_length = 0;
	while (num[num_length] != '\0')
	{
		num_length++;
	}//�Է� ���� ���� ������ ������ �߽��ϴ�.
	if (num_length <= 1)
	{
		return num[0];
	}//�Է¹��� ���� 1�� ������ ��� �Դϴ�.

	GCD = gcd(num[0], num[1]);//ó�� �տ� 2 ���� �ִ� ������� ���ؼ� GCD�� ������ ������ ���־����ϴ�.
	for (int i = 2; i < num_length; ++i)
		GCD = gcd(GCD, num[i]);//�׸��� ���� ������ �ִ������� ��� �ؼ� ���ϸ鼭 ��ü�� �ִ� ������� ���߽��ϴ�. 

	return GCD;
}

void main()
{
	string cmd;
	int num[MAX_NUM];
	int i;
	cout << "���� �Է� : ";

	vector<int> Num_vec;

	getline(cin, cmd);

	string NUM = "";
	for (i = 0; i < cmd.length(); i++)
	{
		if (cmd.at(i) == ' ')
		{
			// ������� ������ ������ Vector�� �߰� �� String�� �ʱ�ȭ ���־����ϴ�.
			Num_vec.push_back(atoi(NUM.c_str()));
			NUM = "";
		}
		else
		{
			// ���Ⱑ ���� ������ ���� �� ���־ ��Ȯ�� ���ڸ� ����� �ִ� �ڵ��Դϴ�.
			NUM += cmd.at(i);
		}

	}
	Num_vec.push_back(atoi(NUM.c_str()));	// ������ ���ڵ� ���Ϳ� �߰��߽��ϴ�.


	for (int x = 0; x < Num_vec.size(); x++)
	{
		num[x] = Num_vec[x];//���Ϳ� �ִ� ������ �迭�� �Ű���ϴ�.
	}
	num[Num_vec.size()] = '\0';
	cout << "�Է� ���� ������ �ִ� ������� : " << N_gcd(num) << endl;
}