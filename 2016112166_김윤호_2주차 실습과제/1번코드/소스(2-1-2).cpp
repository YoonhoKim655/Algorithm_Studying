//2016112166 ����ȣ

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool Is_Palin(string input, int Start, int End)
{
	if (input.length() == 1)
		return true;//�ѱ��� �� ���, ������ ȸ���̹Ƿ� true�� ��ȯ �����ϴ�.
	while (Start < End)
	{
		if (input[Start] != input[End])
		{
			return false;
		}
		Start++;
		End--;///ó���� ���� ���ڰ� �������� �Ǻ��߽��ϴ�.
			Is_Palin(input, Start, End);//start�� end�� ���� 1����,1���Ҹ� �߱⿡, ���� ���� ��ġ �Ǵ� ���ڰ� �������� �Ǻ��� �մϴ�.
	}
		return true;//��� ��찡 false�� �ƴ� ��� true�� ��ȯ�� �߽��ϴ�.
		
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