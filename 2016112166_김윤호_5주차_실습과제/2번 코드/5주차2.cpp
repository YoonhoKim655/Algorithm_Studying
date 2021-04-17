//2016112166 ����ȣ

#include <iostream>

using namespace std;

int cal_coin(int M, int c[], int d,int(&X)[11])//X��� �迭�� �����ؼ� �� M������ �ּ� coin���� ������ �� ���Դϴ�.
{
	if (M == 0) {
		return 0;
	}
		int e_coin = INT_MAX;
		/*�� money�� �ּ� ���� ���� �ϱ� ���� int���� ���� �� �ִ� �ִ��� ������ ������ �ؼ�
		  recursive�� ������ �ݺ��� �ؼ� ���� �ּ��� ������ ���� �� �ְ� �߽��ϴ�.*/
	for (int i = 0; i < d; i++)
	{
		if (M >= c[i])
		{
			int temp = cal_coin(M - c[i], c, d, X);
			/*pdf�� ���� ����� ����� �ؼ� ������ �߽��ϴ�.��� ����� ����� �ؼ� 
			  M���� ��� �� �� �ִ� coin�� �A ������ �ٽ� coin���� ���� �ּ��� ����� ���� ã�� ����Դϴ�.*/
			if (temp != INT_MAX && temp + 1 < e_coin)
				e_coin = temp + 1; 
			/*��͸� ���ؼ� �ݺ��� �Ǹ鼭 �� M�� ���� �� �ִ� �ּ��� ���� ã�� ���ؼ� 
			temp + 1�� ������ e_coin���� ���� �� e_coin�� ���� ���� �߽��ϴ�.*/
		}/*e_coin�� ���� �ּ��� ������ ������ �߽��ϴ�.*/ 
	}
	X[M-1] = e_coin;//�迭�� �� M�� �ּ� coin���� ������ �߽��ϴ�.
	return e_coin;
}


void main()
{
	int money = 11;
	int coin[] = { 1,4,7 };
	int d = sizeof(coin) / sizeof(int);
	int Min_coin[11];//���� ���� coin�� ���� �����ϱ� ���� �迭�Դϴ�.
	cal_coin(money, coin, d, Min_coin);
	for (int i = 0; i < 11; i++)
	{
		cout << "M : " << i+1 << " coin : " << Min_coin[i] << endl;
	}
}