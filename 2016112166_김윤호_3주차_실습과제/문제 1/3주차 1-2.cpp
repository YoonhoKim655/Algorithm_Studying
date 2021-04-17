//2016112166 김윤호

#include <iostream>

#define MAX_SIZE 10
using namespace std;

void merge_sort(int list[])
{
	int mid, right;
	int a, b, x;

	int sorted[MAX_SIZE];//정렬된 배열을 저장을 하기 위한 배열

	for (int k = 1; k < MAX_SIZE; k *= 2) //k는 기준 되는 위치를 정해주는 값입니다. 반복을 통해서 다시 앞에서 부터 정렬을 할 수 있게 해줍니다.
	{
		for (int left = 0; left + k < MAX_SIZE; left += k * 2) 
		{
			mid = left + k;
			right = mid + k;
			//mid와 right의 값을 설정을 했습니다.
			if (right > MAX_SIZE) right = MAX_SIZE;
			x = left; a = left; b = mid;
			while (a < mid && b < right)//이와 같은 조건을 기준으로 while문을 사용을 해서 
			{
				sorted[x++] = (list[a] <= list[b]) ? list[a++] : list[b++];
			}//재귀 부분과 같은 방식으로 정렬을 했고 그 값을 새로운 배열에 넣었습니다.
			while (a < mid) 
			{
				sorted[x++] = list[a++];
			}
			while (b < right) 
			{
				sorted[x++] = list[b++];
			}
			for (x = left; x < right; x++)
			{
				list[x] = sorted[x];
			}//정렬된 배열을 다시 원래의 값들을 저장하는 배열로 저장을 했습니다.
			for(int i = 0; i < MAX_SIZE;i++)
				cout << "|" << list[i] << "|";
			cout << endl;
		}
	}
}

void main()
{
	
		int A[MAX_SIZE] = { 30,20,40,35,5,50,45,10,25,15 };

		merge_sort(A);
	
}