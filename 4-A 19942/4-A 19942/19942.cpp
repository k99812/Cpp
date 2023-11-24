#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

const int MAX = 18, INF = 1e8;
int n, mp, mf, ms, mv, minest = INF;
vector<vector<int>> Nutrient;
map<int, vector<vector<int>>> ret;

bool check(int* input)
{
	if (input[0] >= mp && input[1] >= mf && input[2] >= ms && input[3] >= mv)
	{
		return true;
	}

	return false;
}

void combi()
{
	for (int i = 1; i < (1 << n); i++)
	{
		vector<int> temp;
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
			{
				temp.push_back(j);
			}
		}

		if (temp.size())
		{
			int sum[5] = {0, 0, 0, 0, 0};
		
			for (int a : temp)
			{
				for (int i = 0; i < 5; i++)
				{
					sum[i] += Nutrient[a][i];
				}
			}

			if (check(sum))
			{
				if (sum[4] <= minest)
				{
					minest = sum[4];
					ret[minest].push_back(temp);
				}
			}
		}
	}
}

int main()
{
	cin >> n >> mp >> mf >> ms >> mv;

	for (int i = 0; i < n; i++)
	{
		int value;
		vector<int> temp;
		for (int j = 0; j < 5; j++)
		{
			cin >> value;
			temp.push_back(value);
		}
		Nutrient.push_back(temp);
	}

	combi();
	if (minest == INF) cout << -1 << "\n";
	else
	{
		sort(ret[minest].begin(), ret[minest].end());
		cout << minest << "\n";
		for (int a : ret[minest][0]) {
			cout << a + 1 << " ";
		}
	}
	return 0;
}