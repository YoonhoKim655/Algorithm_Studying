//2016112166 ����ȣ

#include <iostream>
#include <vector>
#include <string>
#define NUM 10
using namespace std;

void better(int M, int C[], int d)
{

	int K[NUM] = {};//� ������ �� �� ����� �Ǿ��� ���� ��Ÿ�� �迭�Դϴ�.
	cout << "K = (";
	for (int i = 0; i < d; i++)
	{
		K[i] = M / C[i];
		M -= C[i] * K[i];
	}
	//greedybetter����� �ϴ� ū �͵��� ���� �ִ� ����̹Ƿ� M���� �� �� �ִ� ���� ū ���� �־ M�� ���� ����� ����Դϴ�.
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

	better(M, C, d);
}