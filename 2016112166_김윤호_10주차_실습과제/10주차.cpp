//2016112166 김윤호

#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool ** make_graph(vector<string> spec, int n)//n은 입력되는 문자열의 길이
{
	int x = spec.size();

	int S_length = (n * spec.size() - (n - 1)*(spec.size() - 2));//복원되는 문자열의 길이
	bool ** graph = new bool *[x];
	/* vector의 저장된 문자열이 서로 SHB에 따라서 움직이는 연결이 가능하면 1을 입력
	연결이 불가능하면 0을 입력을 해서 저장을 했습니다.*/
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
	/*갈 수 있는 vertex인지를 확인*/
	for (int i = 0; i < p; i++)
	{
		if (path[i] == x)
			return false;
	}
	/*vertex를 왔다 갔는 지를 판단해준다.*/

	return true;
}//이 함수는 vertex를 경유를 했는지를 판단을 해주는 함수입니다.

bool hamiltonsub(bool ** graph, int path[], int p, int size)
{
	if (p == size)
	{
		if (graph[path[p - 1]][path[0]] == 1)
			return false;
		else
			return true;
	}//path를 발견을 했는지를 판단을 하는 부분

	for (int v = 1; v < size; v++)
	{
		if (via(v, graph, path, p))
		{
			path[p] = v;

			if (hamiltonsub(graph, path, p + 1, size) == true)
				return true;
			/*재귀방식을 사용을 해서 모든 vertex들을 참조를 했습니다. 
			그래서 모든 vertex를 가보았으면 true를 return 했습니다.*/
			path[p] = -1;
			//참조 받지 못한 것은 -1로 저장을 했습니다.
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
	//vertex들의 path를 -1로 초기화를 했습니다.

	path[0] = 0;
	if (hamiltonsub(graph, path, 1, size) == false)
	{
		cout << "solution does not exist" << endl;
		return false;
	}//path를 찾지 못 했을 경우, false를 return을 하고 답이 없다고 출력을 했습니다.
	for (int x = 0; x < size; x++)
	{
		string temp = s[path[x]];
		
		if (x == 0)
			origin = temp;//처음의 위치하는 문자열은 복원하기 위한 문자열에 그대로 저장을 했습니다.
		
		else
		{
			char back = temp.back();//temp의 마지막 문자를 back이라는 변수에 저장을 했습니다.
			origin += back;// 그리고 origin 문자열에 합해서 문자열을 복원을 하는 방식을 사용을 했습니다.
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