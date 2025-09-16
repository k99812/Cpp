#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

int n, k, d;
vector<pair<int, int>> student;
unordered_map<int, vector<int>> algo;

int main()
{
	cin >> n >> k >> d;

	student = vector<pair<int, int>>(n);

	for (int i = 0; i < n; i++)
	{
		int m, s;
		cin >> m >> s;

		student[i] = { m, s };
		vector<int> temp(m);

		for (int j = 0; j < m; j++)
		{
			cin >> temp[j];
		}

		algo[i] = temp;
	}

	return 0;
}