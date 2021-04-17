//2016112166 김윤호

#include <iostream>
#include <vector>
#include <string>
#define NUM 10
using namespace std;


void main()
{
	int M = 1;
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

	while (M < 101)//1~100까지의 수를 비교 하기 위해 while문을 사용을 했습니다.
	{
		int K_G[6] = {};//어떤 동전이 몇 번 사용이 되었는 지를 greedy방식을 사용해 결정된 값을 나타낼 배열입니다.

		int M_G = M;
		for (int i = 0; i < d; i++)
		{
			K_G[i] = M_G / C[i];
			M_G -= C[i] * K_G[i];
		}
		//greedybetter방식은 일단 큰 것들을 먼저 넣는 방식이므로 M값에 들어갈 수 있는 가장 큰 값을 넣어서 M의 값을 만드는 방식입니다.

		int K_B[6] = {};//어떤 동전이 몇 번 사용이 되었는 지를 brute force방식을 사용해 결정된 값을 나타낼 배열입니다.
		int M_B = M;
		for (int q = 0; q < d; q++)
		{
			K_B[q] = M_B / C[q];//각 동전이 주어진 값에 대해 최대 몇 번 사용을 할 수 있는지를 저장을 했습니다.
		}
		int count = 0;//사용된 동전의 수를 저장을 하기 위한 변수 입니다.

		int sum, smallest = M_B;//가장 적은 수를 사용한 값을 저장을 하기 위해서 smallest라는 변수를 사용을 해서 초기값을 주어진 값을 넣어주었습니다.
		for (int a = 0; a < K_B[5]; a++)
		{
			sum = 0;
			count = 0;
			for (int i = 0; i <= K_B[4]; i++)
			{
				for (int j = 0; j <= K_B[3]; j++)
				{
					for (int k = 0; k <= K_B[2]; k++)
					{
						for (int l = 0; l <= K_B[1]; l++)
						{
							for (int m = 0; m <= K_B[0]; m++)
							{
								sum = C[5] * a + C[4] * i + C[3] * j + C[2] * k + C[1] * l + C[0] * m;//동전과 그 동전의 수를 곱하고 다른 것과 더했습니다.
								if (sum == M_B)
								{
									count = i + j + k + l + m + a;//사용된 동전의 수입니다.
									if (count <= smallest)
									{
										smallest = count;
										K_B[0] = m;
										K_B[1] = l;
										K_B[2] = k;
										K_B[3] = j;
										K_B[4] = i;
										K_B[5] = a;
									}
								}//더해진 값이 주어진 값과 같다면, 동전의 수가 전에 있던 동전이 사용된 수보다 작거나 같으면 smallest의 값을 count의 값으로 바꿔주고, K_B배열도 다시 바꿔주었습니다. 
							}
						}
						//k[i]가 가능한 모든 값들을 모두 적용을 해서 사용된 동전의 수가 가장 작은 값일 때, 사용된 동전의 종류와 수를 저장을 했습니다.
					}
				}
			}
		}
		bool same = true;
		for (int i = 0; i < d; i++)
		{
			if (K_G[i] != K_B[i])
				same = false;
		}//두개의 방식을사용해서 결정된 동전의 수가 다르다면 same이라는 bool type변수에 false를 저장을 했습니다.
		
		if (same == false)
		{
			cout << "서로 다른 결과 : " << endl;
			cout << "M : " << M << endl;

			cout << "K_B = (";
			for (int i = 0; i < d; i++)
			{
				cout << " " << K_B[i];
			}
			cout << ")" << endl;
			cout << "K_G = (";
			for (int i = 0; i < d; i++)
			{
				cout << " " << K_G[i];
			}
			cout << ")"<<endl;
		}//서로 다른 값이 저장이 되었을 경우, 각각의 배열을 출력을 했습니다.
		M++;
	}

}