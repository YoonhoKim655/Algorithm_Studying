//2016112166 ����ȣ

#include <iostream>
#include <vector>
#include <string>
#define NUM 10
using namespace std;


void main()
{
	int M = 1;
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

	while (M < 101)//1~100������ ���� �� �ϱ� ���� while���� ����� �߽��ϴ�.
	{
		int K_G[6] = {};//� ������ �� �� ����� �Ǿ��� ���� greedy����� ����� ������ ���� ��Ÿ�� �迭�Դϴ�.

		int M_G = M;
		for (int i = 0; i < d; i++)
		{
			K_G[i] = M_G / C[i];
			M_G -= C[i] * K_G[i];
		}
		//greedybetter����� �ϴ� ū �͵��� ���� �ִ� ����̹Ƿ� M���� �� �� �ִ� ���� ū ���� �־ M�� ���� ����� ����Դϴ�.

		int K_B[6] = {};//� ������ �� �� ����� �Ǿ��� ���� brute force����� ����� ������ ���� ��Ÿ�� �迭�Դϴ�.
		int M_B = M;
		for (int q = 0; q < d; q++)
		{
			K_B[q] = M_B / C[q];//�� ������ �־��� ���� ���� �ִ� �� �� ����� �� �� �ִ����� ������ �߽��ϴ�.
		}
		int count = 0;//���� ������ ���� ������ �ϱ� ���� ���� �Դϴ�.

		int sum, smallest = M_B;//���� ���� ���� ����� ���� ������ �ϱ� ���ؼ� smallest��� ������ ����� �ؼ� �ʱⰪ�� �־��� ���� �־��־����ϴ�.
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
								sum = C[5] * a + C[4] * i + C[3] * j + C[2] * k + C[1] * l + C[0] * m;//������ �� ������ ���� ���ϰ� �ٸ� �Ͱ� ���߽��ϴ�.
								if (sum == M_B)
								{
									count = i + j + k + l + m + a;//���� ������ ���Դϴ�.
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
								}//������ ���� �־��� ���� ���ٸ�, ������ ���� ���� �ִ� ������ ���� ������ �۰ų� ������ smallest�� ���� count�� ������ �ٲ��ְ�, K_B�迭�� �ٽ� �ٲ��־����ϴ�. 
							}
						}
						//k[i]�� ������ ��� ������ ��� ������ �ؼ� ���� ������ ���� ���� ���� ���� ��, ���� ������ ������ ���� ������ �߽��ϴ�.
					}
				}
			}
		}
		bool same = true;
		for (int i = 0; i < d; i++)
		{
			if (K_G[i] != K_B[i])
				same = false;
		}//�ΰ��� ���������ؼ� ������ ������ ���� �ٸ��ٸ� same�̶�� bool type������ false�� ������ �߽��ϴ�.
		
		if (same == false)
		{
			cout << "���� �ٸ� ��� : " << endl;
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
		}//���� �ٸ� ���� ������ �Ǿ��� ���, ������ �迭�� ����� �߽��ϴ�.
		M++;
	}

}