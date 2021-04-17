//2016112166 ����ȣ

#include <iostream>
#include <string>

using namespace std;

struct BWT {
	int index;
	string suffix;
};

string computeSuffixArray(string input_text, int len_text)
{
	struct BWT * suff = new BWT [len_text+1];
	string * str = new string[len_text+1];
	string bwt_arr;
	string pre;
	input_text += '$';

	for (int i = 0; i < len_text+1; i++)
	{
		suff[len_text - i].index = i;
		suff[len_text - i].suffix = input_text.substr(i) ;
	}//BWT ����ü�� suffix�� index�� ä���ִ� �κ��Դϴ�.

	cout << "Fill the rest" << endl;
	for (int i = 0; i < len_text+1; i++)
	{
		str[i] = suff[i].suffix;
		for (int j = 0; j < len_text - i; j++)
		{
			str[i] += input_text[j];
		}
		cout << str[i] << endl;
	}
	cout << endl;
	//�տ��� ä�� suffix���� ������ ���ڿ��� �Բ� ����� �߽��ϴ�.

	for (int i = 0; i < len_text; i++)
	{
		for (int j = 0; j < len_text-i; j++)
		{
			if (suff[j].suffix.compare(suff[j+1].suffix) > 0)
			{
				BWT temp = suff[j];
				suff[j] = suff[j + 1];
				suff[j + 1] = temp;
			}
		}
	}
	//���� ������ ����� �ؼ� sort�� �߽��ϴ�.

	// Stores the indexes of sorted rotations 
	int* suffix_arr = new int [len_text];
	for (int i = 0; i < len_text; i++)
		suffix_arr[i] = suff[i].index;

	BWT * bwt_a = new BWT[len_text + 1];
	BWT * pre_a = new BWT[len_text + 1];

	/*�ϳ��� bwt�� ������ ������ ���ڵ��� �����ϱ� ���� ���̰�,
	�ٸ� �ϳ��� ������ ���� ������ �ؼ� ���� �տ� ���� ���ڸ� ������ �մϴ�.*/

	cout << "sort" << endl;
	for (int i = 0; i < len_text + 1; i++)
	{
		str[i] = suff[i].suffix;
		bwt_a[i].index = i;
		pre_a[i].index = i;
		int k = str[i].length();
		for (int j = 0; j <= len_text - k; j++)
		{
			str[i] += input_text[j];
		}
		cout << str[i] << endl;
		bwt_a[i].suffix = str[i].back();
		pre_a[i].suffix = str[i].back();
		bwt_arr += str[i].back();
	}
	cout << endl;
	//sort�� suffix�� ���̸� ����ؼ� sort�� ���� �������� ä���� ����� �߽��ϴ�.
	/*���� ���� bwt_a�� pre_a�� ������ �߽��ϴ�.*/

	cout << "Burrows - Wheeler Transform : " << bwt_arr << endl;

	for (int i = 0; i < len_text; i++)
	{
		for (int j = 0; j < len_text - i; j++)
		{
			if (pre_a[j].suffix.compare(pre_a[j + 1].suffix) > 0)
			{
				BWT temp = pre_a[j];
				pre_a[j] = pre_a[j + 1];
				pre_a[j + 1] = temp;
			}//pre_a�� ����� ������ �񱳸� �ؼ� ������ �°� ������ ���׽��ϴ�.
		}
	}
	
	int count = 0;
	string rev_origin = bwt_a[0].suffix;
	
	int x = 0;
	while (count < len_text)
	{
		int k = 0;
		while (bwt_a[x].index != pre_a[k].index)
		{
			k++;
		}
		x = k;
		rev_origin +=  bwt_a[x].suffix;
		count++;
	}
	/*bwt_a�� ���� ���� ������ �� ���� rev_origin�� �߰��� �ϰ� �� ���� ������ �ִ� index���� ���� ���� 
	������ �ִ� pre_a�� ���� ã�Ƽ� �� �Ͱ� ���� line�� �ִ� bwt_a�� ���� �� rev_origin�� �־��ִ� �����
	����� �ؼ� origin���ڿ� �ݴ밡 �Ǵ� ���ڿ��� ã�ҽ��ϴ�.*/
	string origin;
	count = 0;
	rev_origin.pop_back();
	while (count < len_text)
	{
		origin += rev_origin.back();
		rev_origin.pop_back();
		count++;
	}
	//�׷��� �ݴ밡 �Ǵ� ���ڿ����� ������ ���ڸ� origin�� �������ϴ� ������� origin���ڿ��� ��������ϴ�.
	cout <<"origin : "<< origin << endl;

	return origin;
}


int main()
{
	string input_text = "missisippi";
	int len_text = input_text.length() ;

	string origin = computeSuffixArray(input_text, len_text);

	return 0;
}