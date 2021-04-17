//2016112166 김윤호
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#define MAX 256

using namespace std;

void avr(int num[MAX])
{
	int x = 0;
	cout << "AVR 출력" << endl;
	float sum = 0;
	while (num[x] != '\0')//num배열의 값이 아무것도 없을 때 까지 반복을 합니다.
	{
		sum += num[x];
		
		cout << "AVR[" << x << "] : " << sum / (x + 1) << endl;
		x++;
	}//시간 복잡도가 n이 되기 위해서  sum을 배열에 저장된 값을 계속 저장을 하면서 출력을 동시에 했습니다.
}

void main()
{
	string cmd;
	vector<int> Num_vec;
	
	int num[MAX];
	int s = 0;
	int i;
	cout << "배열을 입력해주세요 : ";
	
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
	Num_vec.push_back(atoi(NUM.c_str()));	// 마지막 숫자도 벡터에 추가를 했습니다.

	
	for (int x = 0; x < Num_vec.size(); x++)
	{
		num[x] = Num_vec[x];
	}//벡터에 있는 모든 값을 num배열로 옮겼습니다.
	num[Num_vec.size()] = '\0';  // 입력 받은 수보다 큰 곳은 제외하기 위해서 큰 부분의 처음 값을 null값을 넣었습니다.
	avr(num);
}