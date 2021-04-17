//2016112166 김윤호
#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <map>
#include <random>
#include <time.h>

using namespace std;

void make_ref(char * ref, string F_name)//make_ref(string F_name)/*string F_name*/
{

	random_device rd;//seed 값을 얻기 위한 random_device 생성
	mt19937 gen(rd());//random_device를 통해 난수 생성 엔진을 초기화 
	uniform_int_distribution<int> dis(0, 3);//0~3의 값을 랜덤으로 생성을 하는 균등 분포 정의
	int i = 0;
	int a = 0, b = 0, c = 0, d = 0;
	while (i < 500000)
	{
		int x = dis(gen);

		switch (x)
		{
		case 0:
			ref[i] = 'A';
			i++;
			a++;
			break;
		case 1:
			ref[i] = 'C';
			i++;
			b++;
			break;
		case 2:
			ref[i] = 'G';
			i++;
			c++;
			break;
		case 3:
			ref[i] = 'T';
			i++;
			d++;
			break;
		}/*switch문을 사용을 해서 생성되는 random값에 따라서 reference DNA sequence를 생성*/
	}
	ref[500000] = '\0';
	cout << "a : " << a << " b : " << b << " c : " << c << " d : " << d << " 합 : " << (a + b + c + d) << endl;

	ofstream ref_file(F_name);
	ref_file << ref << endl;
	ref_file.close();//file을 저장
	delete[] ref;
}

void make_myDNA(string ref_file, string my_DNA, int k)
{
	char *my = new char[5000001];
	char *my1 = new char[5000001];
	ifstream refer(ref_file);
	refer.getline(my1, 500001);
	refer.close();// 생성한 reference DNA를 가지고 옮

	int a = (2 * (500000 / k));	//x%

	my = my1;
	random_device rd;//seed 값을 얻기 위한 random_device 생성
	mt19937 gen(rd());//random_device를 통해 난수 생성 엔진을 초기화 
	uniform_int_distribution<int> dis(0, 499999);
	uniform_int_distribution<int> new_dis(0, 2);

	for (int i = 0; i <= a; i++)
	{
		int x = dis(gen);
		int new_x = new_dis(gen);

		if (my[x] == 'A')
		{
			switch (new_x)
			{
			case 0:
				my[x] = 'G';
				break;
			case 1:
				my[x] = 'C';
				break;
			case 2:
				my[x] = 'T';
				break;
			}
		}

		else if (my[x] == 'C')
		{
			switch (new_x)
			{
			case 0:
				my[x] = 'A';
				break;
			case 1:
				my[x] = 'G';
				break;
			case 2:
				my[x] = 'T';
				break;
			}
		}

		else if (my[x] == 'G')
		{
			switch (new_x)
			{
			case 0:
				my[x] = 'A';
				break;
			case 1:
				my[x] = 'C';
				break;
			case 2:
				my[x] = 'T';
				break;
			}
		}

		else
		{
			switch (new_x)
			{
			case 0:
				my[x] = 'A';
				break;
			case 1:
				my[x] = 'C';
				break;
			case 2:
				my[x] = 'G';
				break;
			}
		}
	}
	/*랜덤한 값을 입력을 받아서 reference DNA의 위치를 결정을 하고 그 위치의 값에 따라서 다시 random값을 입력을 받아서 값에 따라서 새로 입력을 
	받는 값이 정해지는 방식으로 myDNA를 새로 만들었습니다.*/
	my[500000] = '\0';

	ofstream my_file(my_DNA);
	my_file << my << endl;
	my_file.close();
}

void shortread(string my_name, string short_name, int k, int n)
{
	random_device rd;//seed 값을 얻기 위한 random_device 생성
	mt19937 gen(rd());//random_device를 통해 난수 생성 엔진을 초기화 
	uniform_int_distribution<int> dis(0, 500000 - k);

	char *my = new char[5000001];

	ifstream refer(my_name);
	refer.getline(my, 500001);//myDNA를 문자열에 저장
	refer.close();

	char * short_read = new char[k + 1];
	ofstream short_file(short_name);
	for (int i = 0; i < n; i++)
	{
		int x = dis(gen);
		for (int j = 0; j < k; j++)
		{
			short_read[j] = my[x + j];
		}
		short_read[k] = '\0';
		short_file << short_read << endl;
	}//랜덤한 값을 입력을 받고서 그 값을 시작점으로 정해서 주어진 길이만큼의 shortread를 만들었습니다.
	short_file.close();
}

void sequence(string short_name, string newname, string ref_file, int k, int n)
{
	char * short_read = new char[k + 1];
	char * short_read1 = new char[k + 1];
	char * ref_ = new char[500001];
	char * new_my = new char[500001];
	char * ref_1 = new char[500001];
	char * new_my1 = new char[500001];

	ifstream refer(ref_file);
	refer.getline(ref_, 500001);
	refer.close();


	ifstream refer_(ref_file);
	refer_.getline(new_my, 500001);
	refer_.close();
	ref_1 = ref_;
	new_my1 = new_my;
	//cout << ref_1 << endl;
	ifstream short_file(short_name);
	
	while (!short_file.eof())
	{
		short_file.getline(short_read, k + 1);
		short_read1 = short_read;
		//cout << short_read1 << endl;
		for (int i = 0; i <= 500000 - k; i++)
		{
			int j;
			int x = 0;
			/*index i에서 pattern 문자열을 확인을 해줍니다.*/
			for (j = 0; j < k; j++)
			{
				if (ref_1[i + j] != short_read1[j])
					x++;
				if (x > 2)//missmatch의 값을 설정을 해서 그 이상일 경우 break를 했습니다.
					break;
			}
			if (j == k && x < 3)
			{
				for (int a = 0; a < k; a++)
				{
					//if(short_read[a] == 'A' || short_read[a] == 'C' || short_read[a] == 'G' || short_read[a] == 'T')
						new_my1[i + a] = short_read1[a];
				}
			}
		}
	}
	
	short_file.close();
	new_my = new_my1;
	ofstream my_file(newname);
	my_file << new_my << endl;
	my_file.close();
	delete[] short_read;
	delete[] ref_;
}

float err_rate(string my, string new_my)
{
	float err = 0.0f;
	float rate;
	char * DNA = new char[500001];
	char * new_DNA = new char[500001];
	char * DNA_ = new char[500001];
	char * new_DNA_ = new char[500001];

	ifstream myDNA(my);
	myDNA.getline(DNA, 500001);
	myDNA.close();
	DNA_ = DNA;

	ifstream new_MD(new_my);
	new_MD.getline(new_DNA, 500001);
	new_MD.close();
	new_DNA_ = new_DNA;

	for (int i = 0; i < 500000; i++)
	{
		if(DNA_[i] != new_DNA_[i])
			err++;
	}
	cout << err << endl;
	rate = (float)((err / 500000)*100);
	return rate;
}

int main()
{
	char *ref = new char[5000001];
	char *ref_2 = new char[5000001];

	string ref_name = "ref.txt";
	string my_name = "my.txt";
	string short_name = "short.txt";
	string new_name = "newmy.txt";

	string ref_name_2 = "ref2.txt";
	string my_name_2 = "my2.txt";
	string short_name_2 = "short2.txt";
	string new_name_2 = "newmy2.txt";

	clock_t start, end;
	
	start = clock();
	make_ref(ref, ref_name);
	make_myDNA(ref_name, my_name, 30);
	shortread(my_name, short_name, 30, 20000);
	sequence(short_name, new_name, ref_name,30, 20000);
	cout << "오차율 : " << err_rate(my_name, new_name) << "%" << endl;
	end = clock();
	cout << "수행 시간 : " << ((end - start) / CLOCKS_PER_SEC)<<endl;
	//k=30, n = 20000인 shortread
	start = clock();
	make_ref(ref_2, ref_name_2);
	make_myDNA(ref_name_2, my_name_2, 60);
	shortread(my_name_2, short_name_2, 60, 15000);
	sequence(short_name_2, new_name_2, ref_name_2, 60, 15000);
	cout << "오차율 : " << err_rate(my_name_2, new_name_2) << "%" << endl;
	end = clock();
	cout << "수행 시간 : " << ((end - start) / CLOCKS_PER_SEC) << endl;
	//k=60, n = 15000인 shortread
	return 0;
}