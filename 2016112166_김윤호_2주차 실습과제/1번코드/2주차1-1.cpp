//2016112166 김윤호

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool Is_Palin(string input)
{
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] != input[input.length() - i - 1])
			return false;
	}//입력 받은 문자열에서 회문 검사를 할 때, 서로 대치되는 위치의 것을 비교를 해서 회문 판별을 했습니다.
	return true;
}

void main()
{
	string filePath = "exam_palindrome.txt";

	ifstream openFile(filePath);
	string str;
	while (getline(openFile, str))
	{
		if (Is_Palin(str) == 1)//회문일 경우
			cout << str << "   It is Palindrome " << endl;
		else//회문이 아닐 경우
			cout << str << "   It is not Palindrome " << endl;
	}
	openFile.close();

}