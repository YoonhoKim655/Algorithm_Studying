//2016112166 ����ȣ

#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool ** make_graph(vector<string> spec, int n)//n�� �ԷµǴ� ���ڿ��� ����
{
	int x = spec.size();

	int S_length = (n * spec.size() - (n - 1)*(spec.size() - 2));//�����Ǵ� ���ڿ��� ����
	bool ** graph = new bool *[x];
	/* vector�� ����� ���ڿ��� ���� SHB�� ���� �����̴� ������ �����ϸ� 1�� �Է�
	������ �Ұ����ϸ� 0�� �Է��� �ؼ� ������ �߽��ϴ�.*/
	for (int i = 0; i < x; i++)
	{
		graph[i] = new bool[x];
		for (int j = 0; j < x; j++)
		{
			if (i != j)
			{

				if (spec[i].substr(1) != spec[j].substr(0, n - 1))
					graph[i][j] = false;
				else
					graph[i][j] = true;
			}
			else
				graph[i][j] = false;
			//cout << graph[i][j] << " ";
		}
		//cout << endl;
	}
	return graph;
}

bool via(int x, bool **graph, int path[], int p)
{
	if (graph[path[p - 1]][x] == 0)
		return false;
	/*�� �� �ִ� vertex������ Ȯ��*/
	for (int i = 0; i < p; i++)
	{
		if (path[i] == x)
			return false;
	}
	/*vertex�� �Դ� ���� ���� �Ǵ����ش�.*/

	return true;
}//�� �Լ��� vertex�� ������ �ߴ����� �Ǵ��� ���ִ� �Լ��Դϴ�.

bool hamiltonsub(bool ** graph, int path[], int p, int size)
{
	if (p == size)
	{
		if (graph[path[p - 1]][path[0]] == 1)
			return false;
		else
			return true;
	}//path�� �߰��� �ߴ����� �Ǵ��� �ϴ� �κ�

	for (int v = 1; v < size; v++)
	{
		if (via(v, graph, path, p))
		{
			path[p] = v;

			if (hamiltonsub(graph, path, p + 1, size) == true)
				return true;
			/*��͹���� ����� �ؼ� ��� vertex���� ������ �߽��ϴ�. 
			�׷��� ��� vertex�� ���������� true�� return �߽��ϴ�.*/
			path[p] = -1;
			//���� ���� ���� ���� -1�� ������ �߽��ϴ�.
		}
	}
	return false;
}

bool Hamilton(bool ** graph, vector<string> spec, int size)
{
	string origin;
	vector<string> s = spec;

	int *path = new int[size];
	for (int i = 0; i < size; i++)
		path[i] = -1;
	//vertex���� path�� -1�� �ʱ�ȭ�� �߽��ϴ�.

	path[0] = 0;
	if (hamiltonsub(graph, path, 1, size) == false)
	{
		cout << "solution does not exist" << endl;
		return false;
	}//path�� ã�� �� ���� ���, false�� return�� �ϰ� ���� ���ٰ� ����� �߽��ϴ�.
	for (int x = 0; x < size; x++)
	{
		string temp = s[path[x]];
		
		if (x == 0)
			origin = temp;//ó���� ��ġ�ϴ� ���ڿ��� �����ϱ� ���� ���ڿ��� �״�� ������ �߽��ϴ�.
		
		else
		{
			char back = temp.back();//temp�� ������ ���ڸ� back�̶�� ������ ������ �߽��ϴ�.
			origin += back;// �׸��� origin ���ڿ��� ���ؼ� ���ڿ��� ������ �ϴ� ����� ����� �߽��ϴ�.
		}
	}
	cout << origin << endl;
}

void main()
{
	vector<string> spectrum;
	vector<string> spectrum2;
	vector<string> spectrum3;
	vector<string> spectrum4;


	spectrum.push_back("AGT");
	spectrum.push_back("AAA");
	spectrum.push_back("ACT");
	spectrum.push_back("AAC");
	spectrum.push_back("CTT");
	spectrum.push_back("GTA");
	spectrum.push_back("TTT");
	spectrum.push_back("TAA");

	spectrum2.push_back("ATG");
	spectrum2.push_back("AGG");
	spectrum2.push_back("TGC");
	spectrum2.push_back("TCC");
	spectrum2.push_back("GTC");
	spectrum2.push_back("GGT");
	spectrum2.push_back("GCA");
	spectrum2.push_back("CAG");

	spectrum3.push_back("ATG");
	spectrum3.push_back("TGG");
	spectrum3.push_back("TGC");
	spectrum3.push_back("GTG");
	spectrum3.push_back("GGC");
	spectrum3.push_back("GCA");
	spectrum3.push_back("GCG");
	spectrum3.push_back("CGT");

	spectrum4.push_back("ATGC");
	spectrum4.push_back("TGCG");
	spectrum4.push_back("GCGG");
	spectrum4.push_back("CGGC");
	spectrum4.push_back("GGCT");
	spectrum4.push_back("GCTG");
	spectrum4.push_back("CTGT");
	spectrum4.push_back("TGTA");
	spectrum4.push_back("GTAT");
	spectrum4.push_back("TATG");
	spectrum4.push_back("ATGG");
	spectrum4.push_back("TGGT");
	spectrum4.push_back("GGTG");

	bool ** graph = new bool *[spectrum.size()];
	graph =	make_graph(spectrum, 3);

	cout << "spectrum1-origin string : " << endl;
	Hamilton(graph, spectrum, spectrum.size());

	bool ** graph2 = new bool *[spectrum2.size()];
	graph2 = make_graph(spectrum2, 3);

	cout << "spectrum2-origin string : " << endl;
	Hamilton(graph2, spectrum2, spectrum2.size());

	bool ** graph3 = new bool *[spectrum3.size()];
	graph3 = make_graph(spectrum3, 3);

	cout << "spectrum3-origin string : " << endl;
	Hamilton(graph3, spectrum3, spectrum3.size());

	bool ** graph4 = new bool *[spectrum.size()];
	graph4 = make_graph(spectrum4, 4);

	cout << "spectrum4-origin string : " << endl;
	Hamilton(graph4, spectrum4, spectrum4.size());
}