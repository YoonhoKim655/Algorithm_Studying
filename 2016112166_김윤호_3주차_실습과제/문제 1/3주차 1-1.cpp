//2016112166 김윤호

#include <iostream>
#define MAX_SIZE 10
using namespace std;

void merge(int list[], int left, int mid, int right) 
{
	int i, j, k = left, l;

	int sorted[MAX_SIZE];
	
	for (i = left, j = mid + 1 ; i <= mid && j <= right; )
	{
		sorted[k++] = (list[i] <= list[j]) ? list[i++] : list[j++];//list[i]와 list[j]를 비교해서 더 작은 값의 index에 1을 더했습니다. 이 과정을 정렬이 되지 않은 left가 정렬이 되면서 mid까지 반복을 했습니다.
	}//분할 정렬된 list
	
	if (i > mid)
		for (l = j; l <= right; l++, k++)
		{
			sorted[k] = list[l];
		}
	else
		for (l = i; l <= mid; l++, k++) {
			sorted[k] = list[l];
		}
	//한쪽에 남아 있는 배열들을 복사 해주었습니다.

	for (l = left; l <= right; l++) {
		list[l] = sorted[l];
	}//배열 sorted[] 의 리스트를 배열 list로 재복사를 했습니다.
	for (int i = 0; i < MAX_SIZE; i++)//단계별로 출력을 위해서 merge를 할 때마다 출력을 헀습니다.
		cout << "|" << list[i] << "|";
	cout << endl;
}//정렬 코드

void merge_sort(int list[], int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;//기존에 있던 배열에서 나뉠 부분을 정했습니다.
		merge_sort(list,left, mid);//나뉘는 부분의 왼쪽 부터 나누었습니다.
		merge_sort(list, mid + 1, right);//재귀 부분으로 왼쪽이 끝나면 오른쪽을 나누었습니다.
		merge(list, left, mid, right);//그리고 다시 나누어진 기준을 가지고 정렬을 하는 코드입니다.
	}
}

void main()
{
	int A[MAX_SIZE] = { 30,20,40,35,5,50,45,10,25,15 };

	for (int i = 0; i < MAX_SIZE; i++)
		cout << "|" << A[i] << "|";
	cout << endl;
	merge_sort(A, 0, MAX_SIZE-1);
}