//2016112166 ����ȣ

#include <iostream>
#include <vector>
#include <string>
#define NUM 10
using namespace std;


void main()
{
	int M = 40;
	int C[NUM];
	cout << "COIN�� ������ �Է��ϼ��� : ";
	vector<int> Num_vec;
	string cmd;
	getline(cin, cmd);

	string N = "";
	for (int i = 0; i < cmd.length(); i++)
	{
		if (cmd.at(i) == ' ')
		{
			// ������� ������ ������ Vector�� �߰� �� String�� �ʱ�ȭ ���־����ϴ�.
			Num_vec.push_back(atoi(N.c_str()));
			N = "";
		}
		else
		{
			// ���Ⱑ ���� ������ ���� �� ���־ ��Ȯ�� ���ڸ� ����� �ִ� �ڵ��Դϴ�.
			N += cmd.at(i);
		}

	}
	Num_vec.push_back(atoi(N.c_str()));	// ������ ���ڵ� ���Ϳ� �߰��߽��ϴ�.


	for (int x = 0; x < Num_vec.size(); x++)
	{
		C[x] = Num_vec[x];//���Ϳ� �ִ� ������ �迭�� �Ű���ϴ�.
	}

	int d = Num_vec.size();//�迭 C�� ���̸� ���߽��ϴ�.

	int K[5] = {};

	for (int q = 0; q < d; q++)
	{
		K[q] = M / C[q];//�� ������ �־��� ���� ���� �ִ� �� �� ����� �� �� �ִ����� ������ �߽��ϴ�.
	}
	int count = 0;//���� ������ ���� ������ �ϱ� ���� ���� �Դϴ�
	
	int sum, smallest=M;//���� ���� ���� ����� ���� ������ �ϱ� ���ؼ� smallest��� ������ ����� �ؼ� �ʱⰪ�� �־��� ���� �־��־����ϴ�.

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
						//������ �� ������ ���� ���ϰ� �ٸ� �Ͱ� ���߽��ϴ�.
						if (sum == 40)
						{
							count = i + j + k + l + m;//���� ������ ���Դϴ�.
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
						//������ ���� �־��� ���� ���ٸ�, ������ ���� ���� �ִ� ������ ���� ������ �۰ų� ������ smallest�� ���� count�� ������ �ٲ��ְ�, K_B�迭�� �ٽ� �ٲ��־����ϴ�. 
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