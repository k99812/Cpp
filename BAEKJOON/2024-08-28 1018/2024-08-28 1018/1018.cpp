#include<iostream>
#include<algorithm>
#include<string>

#define MAX_NUM 50 + 4
#define INF 1e9

using namespace std;

int n, m, ret = INF, a[MAX_NUM][MAX_NUM];
const string WB[8] =
{
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW"
};
const string BW[8] =
{
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB"
};

int go(int y, int x)
{
	int WB_Cnt = 0, BW_Cnt = 0,ans = INF;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (WB[i][j] == a[i + y][j + x])
			{
				WB_Cnt++;
			}
			if (BW[i][j] == a[i + y][j + x])
			{
				BW_Cnt++;
			}
		}
	}

	ans = min(ans, min(WB_Cnt, BW_Cnt));

	return ans;
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			a[i][j] = s[j];
		}
	}

	for (int i = 0; i < n - 7; i++)
	{
		for (int j = 0; j < m - 7; j++)
		{
			ret = min(ret, go(i, j));
		}
	}

	cout << ret << "\n";

	return 0;
}