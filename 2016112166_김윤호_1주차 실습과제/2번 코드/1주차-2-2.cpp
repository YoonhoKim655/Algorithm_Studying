//2016112166 김윤호

#include <iostream>
#include <vector>
#include <string>
#define NUM 10
using namespace std;

void better(int M, int C[], int d)
{

	int K[NUM] = {};//어떤 동전이 몇 번 사용이 되었는 지를 나타낼 배열입니다.
	cout << "K = (";
	for (int i = 0; i < d; i++)
	{
		K[i] = M / C[i];
		M -= C[i] * K[i];
	}
	//greedybetter방식은 일단 큰 것들을 먼저 넣는 방식이므로 M값에 들어갈 수 있는 가장 큰 값을 넣어서 M의 값을 만드는 방식입니다.
	for (int i = 0; i < d; i++)
	{
		cout << " "<<K[i];
	}
	cout << ")";
}

void main()
{
	int M = 40;
	
	int C[NUM];
	cout << "COIN의 종류를 입력하세요 : ";
	vector<int> Num_vec;
	string cmd;
	getline(cin, cmd);

	string N = "";
	for (int i = 0; i < cmd.length(); i++)
	{
		if (cmd.at(i) == ' ')
		{
			// 현재까지 저장한 수들을 Vector에 추가 후 String을 초기화 해주었습니다.
			Num_vec.push_back(atoi(N.c_str()));
			N = "";
		}
		else
		{
			// 띄어쓰기가 나올 때까지 문자 더 해주어서 정확한 숫자를 만들어 주는 코드입니다.
			N += cmd.at(i);
		}

	}
	Num_vec.push_back(atoi(N.c_str()));	// 마지막 숫자도 벡터에 추가했습니다.


	for (int x = 0; x < Num_vec.size(); x++)
	{
		C[x] = Num_vec[x];//벡터에 있는 수들을 배열로 옮겼습니다.
	}
	
	int d = Num_vec.size();//배열 C의 길이를 구했습니다.

	better(M, C, d);
}