//2016112166 ����ȣ
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#define MAX 256

using namespace std;

void avr(int num[MAX])
{
	int x = 0;
	cout << "AVR ���" << endl;
	float sum = 0;
	while (num[x] != '\0')//num�迭�� ���� �ƹ��͵� ���� �� ���� �ݺ��� �մϴ�.
	{
		sum += num[x];
		
		cout << "AVR[" << x << "] : " << sum / (x + 1) << endl;
		x++;
	}//�ð� ���⵵�� n�� �Ǳ� ���ؼ�  sum�� �迭�� ����� ���� ��� ������ �ϸ鼭 ����� ���ÿ� �߽��ϴ�.
}

void main()
{
	string cmd;
	vector<int> Num_vec;
	
	int num[MAX];
	int s = 0;
	int i;
	cout << "�迭�� �Է����ּ��� : ";
	
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
	Num_vec.push_back(atoi(NUM.c_str()));	// ������ ���ڵ� ���Ϳ� �߰��� �߽��ϴ�.

	
	for (int x = 0; x < Num_vec.size(); x++)
	{
		num[x] = Num_vec[x];
	}//���Ϳ� �ִ� ��� ���� num�迭�� �Ű���ϴ�.
	num[Num_vec.size()] = '\0';  // �Է� ���� ������ ū ���� �����ϱ� ���ؼ� ū �κ��� ó�� ���� null���� �־����ϴ�.
	avr(num);
}