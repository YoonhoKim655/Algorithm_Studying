//2016112166 김윤호

#include <iostream>
#include <vector>
#include <string>
#define NUM 10
using namespace std;


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

	int K[5] = {};

	for (int q = 0; q < d; q++)
	{
		K[q] = M / C[q];//각 동전이 주어진 값에 대해 최대 몇 번 사용을 할 수 있는지를 저장을 했습니다.
	}
	int count = 0;//사용된 동전의 수를 저장을 하기 위한 변수 입니다
	
	int sum, smallest=M;//가장 적은 수를 사용한 값을 저장을 하기 위해서 smallest라는 변수를 사용을 해서 초기값을 주어진 값을 넣어주었습니다.

	for (int i = 0; i <= K[4]; i++)
	{
		sum = 0;
		int count = 0;
		for (int j = 0; j <= K[3]; j++)
		{
			for (int k = 0; k <= K[2]; k++)
			{	
				for (int l = 0; l <= K[1]; l++)
				{
					for (int m = 0; m <= K[0]; m++)
					{
						sum = C[4] * i + C[3] * j + C[2] * k + C[1] * l + C[0] * m;
						//동전과 그 동전의 수를 곱하고 다른 것과 더했습니다.
						if (sum == 40)
						{
							count = i + j + k + l + m;//사용된 동전의 수입니다.
							if (count < smallest)
							{
								smallest = count;
								K[0] = m;
								K[1] = l;
								K[2] = k;
								K[3] = j;
								K[4] = i;
							}
						}
						//더해진 값이 주어진 값과 같다면, 동전의 수가 전에 있던 동전이 사용된 수보다 작거나 같으면 smallest의 값을 count의 값으로 바꿔주고, K_B배열도 다시 바꿔주었습니다. 
					}
				}

			}
		}
	}


	cout << "K = (";
	for (int i = 0; i < d; i++)
	{
		cout << " " << K[i];
	}
	cout << ")";

}