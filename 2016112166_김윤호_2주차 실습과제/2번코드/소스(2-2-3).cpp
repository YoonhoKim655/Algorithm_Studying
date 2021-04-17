//2016112166 김윤호

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
	}//입력 받은 수의 갯수를 저장을 했습니다.
	if (num_length <= 1)
	{
		return num[0];
	}//입력받은 수가 1개 이하일 경우 입니다.

	GCD = gcd(num[0], num[1]);//처음 앞에 2 수의 최대 공약수를 구해서 GCD의 값으로 저장을 해주었습니다.
	for (int i = 2; i < num_length; ++i)
		GCD = gcd(GCD, num[i]);//그리고 다음 수와의 최대공약수를 계속 해서 구하면서 전체의 최대 공약수를 구했습니다. 

	return GCD;
}

void main()
{
	string cmd;
	int num[MAX_NUM];
	int i;
	cout << "숫자 입력 : ";

	vector<int> Num_vec;

	getline(cin, cmd);

	string NUM = "";
	for (i = 0; i < cmd.length(); i++)
	{
		if (cmd.at(i) == ' ')
		{
			// 현재까지 저장한 수들을 Vector에 추가 후 String을 초기화 해주었습니다.
			Num_vec.push_back(atoi(NUM.c_str()));
			NUM = "";
		}
		else
		{
			// 띄어쓰기가 나올 때까지 문자 더 해주어서 정확한 숫자를 만들어 주는 코드입니다.
			NUM += cmd.at(i);
		}

	}
	Num_vec.push_back(atoi(NUM.c_str()));	// 마지막 숫자도 벡터에 추가했습니다.


	for (int x = 0; x < Num_vec.size(); x++)
	{
		num[x] = Num_vec[x];//벡터에 있는 수들을 배열로 옮겼습니다.
	}
	num[Num_vec.size()] = '\0';
	cout << "입력 받은 수들의 최대 공약수는 : " << N_gcd(num) << endl;
}