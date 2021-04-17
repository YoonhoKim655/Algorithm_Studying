//2016112166 김윤호 

#include <iostream>
#include <string>
#include <cstring>
#include <time.h>

//#define d 256

using namespace std;

void Brute_fore(char pat[], char txt[], int M, int N)
{
	/*txt에서 pattern을 찾는 것이므로 텍스트에서의 시작 index는 텍스트의 길이에서 
	패턴의 길이를 뺸 값보다 크면 안되기에 i의 값을 N-M보다 작거나 같게 설정을 했습니다.*/
	for (int i = 0; i <= N - M; i++)
	{
		int j;
		/*index i에서 pattern 문자열을 확인을 해줍니다.*/
		for (j = 0; j < M; j++)
		{
			if (txt[i + j] != pat[j])
				break;
		}
		if (j == M) 
			cout << "패턴이 텍스트의 " << i << "번째부터 나타남" <<endl;
		/*이 경우는 확인한 txt의 문자 모두가 패턴과 같은 경우이므로
		텍스트의 몇 번째 index에서 나오는 지를 출력을 해줍니다.*/
	}
}

void RKsearch(char pat[], char txt[], int d, int q, int M, int N)
{
	int i, j;
	int p = 0; // 패턴의 해쉬 값  
	int t = 0; // 텍스트의 해쉬 값  
	int h = 1;
 
	for (i = 0; i < M - 1; i++)
		h = (h * d) % q;

	
	for (i = 0; i < M; i++)
	{
		p = (d * p + pat[i]) % q;
		t = (d * t + txt[i]) % q;
	}//호너 방법으로 p, t의 값을 구합니다.

	for (i = 0; i <= N - M; i++)
	{
		if (p == t)//패턴의 해쉬와 어느 구간의 텍스트의  해쉬 값이 같을 경우
		{
			
			for (j = 0; j < M; j++)
			{
				if (txt[i + j] != pat[j])
					break;
			}//문자를 하나씩 비교를 해줍니다.

			
			if (j == M)
				cout << "패턴이 텍스트의 " << i << "번째부터 나타남" << endl;
			/*이 경우는 확인한 txt의 문자 모두가 패턴과 같은 경우이므로
			텍스트의 몇 번째 index에서 나오는 지를 출력을 해줍니다.*/
		}

		if (i < N - M)
		{
			t = (d*(t - txt[i] * h) + txt[i + M]) % q;
			
			if (t < 0)
				t = (t + q);
		}// 다음 텍스트의 해쉬 값을 구해줍니다.
	}
}


void computeSP(char* pat, int M, int* lps)//최대접대부 table을 만들기 위한 함수
{
	int len = 0;

	lps[0] = 0; // 0번쨰 index는 항상 0

	int i = 1;
	while (i < M)
	{
		if (pat[i] == pat[len])
		{
			len++;
			lps[i] = len;
			i++;
		}// 같은 값이 나올 때 table의 값을 1씩 증가를 해줍니다.
		else
		{
			if (len != 0) 
			{
				len = lps[len - 1];
			}/*lps에 넣어주는 index는 변하지 않고서 
			 pat에서 비교하는 위치가 변하게 됩니다..*/
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

void KMPSearch(char* pat, char* txt, int M, int N)
{
	
	int *lps = new int[M];//최대 접두부 table

	computeSP(pat, M, lps);

	int i = 0;
	int j = 0;
	while (i < N) {
		if (pat[j] == txt[i])
		{
			j++;
			i++;
		}

		if (j == M) 
		{
			cout << "패턴이 텍스트의 " << i-j << "번째부터 나타남" << endl;
			j = lps[j - 1];
		}//텍스트에서 패턴의 문자열을 찾은 경우

		else if (i < N && pat[j] != txt[i])
		{
			if (j != 0)
				j = lps[j - 1];
			/*패턴 문자열의 새로운 index 위치를 최대 접두부 table을
			사용을 해서 지정을 해줍니다.*/
			else
				i = i + 1;
		}
	}
	delete[] lps;
}

void main()
{

	char* txt = new char[100];
	cout << "Text String 입력 : ";
	cin >> txt;
	cout << txt << endl;

	char* pat = new char[100];
	cout << "Pattern String 입력 : ";
	cin >> pat;
	cout << pat << endl;
	int M = strlen(pat);
	int N = strlen(txt);

	clock_t start_T, end_T;
	double result;
	start_T = clock();
	cout << "Brute-Force : " << endl;
	Brute_fore(pat, txt, M, N);
	end_T = clock();
	result = (double)(end_T - start_T);
	cout << "Time : "<< ((result) / CLOCKS_PER_SEC ) <<endl;

	start_T = clock();
	cout << "Rabin-KarP : " << endl;
	RKsearch(pat, txt, 36, 101, M, N);
	/*36을 넣은 것은 알파벳과 0~9까지 수의 합인 36을 알파벳의 크기로 정했습니다.
	그리고 q를 101으로 한 것은 최대 소수를 위해서 넣었습니다.*/
	end_T = clock();
	result = (double)(end_T - start_T);
	cout << "Time : " << ((result) / CLOCKS_PER_SEC) << endl;

	start_T = clock();
	cout << "KMP : " << endl;
	KMPSearch(pat, txt, M, N);
	end_T = clock();
	result = (double)(end_T - start_T);
	cout << "Time : " << ((result) / CLOCKS_PER_SEC) << endl;

	delete[] txt;
	delete[] pat;
}