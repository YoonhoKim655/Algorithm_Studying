//2016112166 ����ȣ

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
	}//�Է� ���� ���ڿ����� ȸ�� �˻縦 �� ��, ���� ��ġ�Ǵ� ��ġ�� ���� �񱳸� �ؼ� ȸ�� �Ǻ��� �߽��ϴ�.
	return true;
}

void main()
{
	string filePath = "exam_palindrome.txt";

	ifstream openFile(filePath);
	string str;
	while (getline(openFile, str))
	{
		if (Is_Palin(str) == 1)//ȸ���� ���
			cout << str << "   It is Palindrome " << endl;
		else//ȸ���� �ƴ� ���
			cout << str << "   It is not Palindrome " << endl;
	}
	openFile.close();

}