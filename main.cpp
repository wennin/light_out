#include"solution.h"


void Print(vector<vector<int>>&v)
{
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[0].size(); j++)
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}


int main()
{
	//cout << "请输入行和列：" << endl;
	//int n, m;
	//cin >> n;
	//cin >> m;
	//vector<vector<int >>a(n*m, vector<int>(n*m));
	equation f(5);
	Print(f.A);
	Print(f.end_result);
	/*for (auto& x : f.now_result)
	{
		cout << x << ' ';
	}*/


	system("pause");
	return 0;
}