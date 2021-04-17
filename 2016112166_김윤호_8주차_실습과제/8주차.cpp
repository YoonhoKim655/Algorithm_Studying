//2016112166 ����ȣ 

#include <iostream>
#include <string>
#include <cstring>
#include <time.h>

//#define d 256

using namespace std;

void Brute_fore(char pat[], char txt[], int M, int N)
{
	/*txt���� pattern�� ã�� ���̹Ƿ� �ؽ�Ʈ������ ���� index�� �ؽ�Ʈ�� ���̿��� 
	������ ���̸� �A ������ ũ�� �ȵǱ⿡ i�� ���� N-M���� �۰ų� ���� ������ �߽��ϴ�.*/
	for (int i = 0; i <= N - M; i++)
	{
		int j;
		/*index i���� pattern ���ڿ��� Ȯ���� ���ݴϴ�.*/
		for (j = 0; j < M; j++)
		{
			if (txt[i + j] != pat[j])
				break;
		}
		if (j == M) 
			cout << "������ �ؽ�Ʈ�� " << i << "��°���� ��Ÿ��" <<endl;
		/*�� ���� Ȯ���� txt�� ���� ��ΰ� ���ϰ� ���� ����̹Ƿ�
		�ؽ�Ʈ�� �� ��° index���� ������ ���� ����� ���ݴϴ�.*/
	}
}

void RKsearch(char pat[], char txt[], int d, int q, int M, int N)
{
	int i, j;
	int p = 0; // ������ �ؽ� ��  
	int t = 0; // �ؽ�Ʈ�� �ؽ� ��  
	int h = 1;
 
	for (i = 0; i < M - 1; i++)
		h = (h * d) % q;

	
	for (i = 0; i < M; i++)
	{
		p = (d * p + pat[i]) % q;
		t = (d * t + txt[i]) % q;
	}//ȣ�� ������� p, t�� ���� ���մϴ�.

	for (i = 0; i <= N - M; i++)
	{
		if (p == t)//������ �ؽ��� ��� ������ �ؽ�Ʈ��  �ؽ� ���� ���� ���
		{
			
			for (j = 0; j < M; j++)
			{
				if (txt[i + j] != pat[j])
					break;
			}//���ڸ� �ϳ��� �񱳸� ���ݴϴ�.

			
			if (j == M)
				cout << "������ �ؽ�Ʈ�� " << i << "��°���� ��Ÿ��" << endl;
			/*�� ���� Ȯ���� txt�� ���� ��ΰ� ���ϰ� ���� ����̹Ƿ�
			�ؽ�Ʈ�� �� ��° index���� ������ ���� ����� ���ݴϴ�.*/
		}

		if (i < N - M)
		{
			t = (d*(t - txt[i] * h) + txt[i + M]) % q;
			
			if (t < 0)
				t = (t + q);
		}// ���� �ؽ�Ʈ�� �ؽ� ���� �����ݴϴ�.
	}
}


void computeSP(char* pat, int M, int* lps)//�ִ������ table�� ����� ���� �Լ�
{
	int len = 0;

	lps[0] = 0; // 0���� index�� �׻� 0

	int i = 1;
	while (i < M)
	{
		if (pat[i] == pat[len])
		{
			len++;
			lps[i] = len;
			i++;
		}// ���� ���� ���� �� table�� ���� 1�� ������ ���ݴϴ�.
		else
		{
			if (len != 0) 
			{
				len = lps[len - 1];
			}/*lps�� �־��ִ� index�� ������ �ʰ� 
			 pat���� ���ϴ� ��ġ�� ���ϰ� �˴ϴ�..*/
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
	
	int *lps = new int[M];//�ִ� ���κ� table

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
			cout << "������ �ؽ�Ʈ�� " << i-j << "��°���� ��Ÿ��" << endl;
			j = lps[j - 1];
		}//�ؽ�Ʈ���� ������ ���ڿ��� ã�� ���

		else if (i < N && pat[j] != txt[i])
		{
			if (j != 0)
				j = lps[j - 1];
			/*���� ���ڿ��� ���ο� index ��ġ�� �ִ� ���κ� table��
			����� �ؼ� ������ ���ݴϴ�.*/
			else
				i = i + 1;
		}
	}
	delete[] lps;
}

void main()
{

	char* txt = new char[100];
	cout << "Text String �Է� : ";
	cin >> txt;
	cout << txt << endl;

	char* pat = new char[100];
	cout << "Pattern String �Է� : ";
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
	/*36�� ���� ���� ���ĺ��� 0~9���� ���� ���� 36�� ���ĺ��� ũ��� ���߽��ϴ�.
	�׸��� q�� 101���� �� ���� �ִ� �Ҽ��� ���ؼ� �־����ϴ�.*/
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