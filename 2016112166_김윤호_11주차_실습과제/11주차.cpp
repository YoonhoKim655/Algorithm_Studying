//2016112166 김윤호

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
	}//BWT 구조체에 suffix와 index를 채워주는 부분입니다.

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
	//앞에서 채운 suffix들을 나머지 문자열과 함께 출력을 했습니다.

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
	//버블 정렬을 사용을 해서 sort를 했습니다.

	// Stores the indexes of sorted rotations 
	int* suffix_arr = new int [len_text];
	for (int i = 0; i < len_text; i++)
		suffix_arr[i] = suff[i].index;

	BWT * bwt_a = new BWT[len_text + 1];
	BWT * pre_a = new BWT[len_text + 1];

	/*하나는 bwt로 생성된 마지막 문자들을 저장하기 위한 것이고,
	다른 하나는 마지막 줄을 정렬을 해서 제일 앞에 오는 문자를 결정을 합니다.*/

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
	//sort된 suffix의 길이를 고려해서 sort된 것을 나머지를 채워서 출력을 했습니다.
	/*또한 새로 bwt_a와 pre_a를 생성을 했습니다.*/

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
			}//pre_a에 저장된 값들을 비교를 해서 순서에 맞게 정렬을 시켰습니다.
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
	/*bwt_a에 가장 먼저 저장이 된 값을 rev_origin에 추가를 하고 그 값이 가지고 있는 index값과 같은 값을 
	가지고 있는 pre_a의 값을 찾아서 그 것과 같은 line에 있는 bwt_a의 값을 또 rev_origin에 넣어주는 방식을
	사용을 해서 origin문자와 반대가 되는 문자열을 찾았습니다.*/
	string origin;
	count = 0;
	rev_origin.pop_back();
	while (count < len_text)
	{
		origin += rev_origin.back();
		rev_origin.pop_back();
		count++;
	}
	//그래서 반대가 되는 문자열에서 마지막 문자를 origin에 저장을하는 방식으로 origin문자열을 만들었습니다.
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