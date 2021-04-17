//2016112166 김윤호

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool Is_Palin(string input, int Start, int End)
{
	if (input.length() == 1)
		return true;//한글자 일 경우, 무조건 회문이므로 true를 반환 헀습니다.
	while (Start < End)
	{
		if (input[Start] != input[End])
		{
			return false;
		}
		Start++;
		End--;///처음과 끝의 문자가 같은지를 판별했습니다.
			Is_Palin(input, Start, End);//start와 end가 각각 1증가,1감소를 했기에, 각각 다음 대치 되는 문자가 같은지를 판별을 합니다.
	}
		return true;//모든 경우가 false가 아닐 경우 true를 반환을 했습니다.
		
}

void main()
{
	string filePath = "exam_palindrome.txt";

	ifstream openFile(filePath);
	string str;
	while (getline(openFile, str))
	{
		if (Is_Palin(str, 0, str.length()-1) == true)
			cout << str << "   It is Palindrome " << endl;
		else
			cout << str << "   It is not Palindrome " << endl;
	}
	openFile.close();

}