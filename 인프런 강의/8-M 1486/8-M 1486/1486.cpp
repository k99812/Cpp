#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

const int INF = 1e9;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n, m, t, d, a[28][28], b[3000][3000], ret;
vector<int> v;
string s;

int main()
{
	cin >> n >> m >> t >> d;

	fill(&b[0][0], &b[2999][3000], INF);

	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < s.size(); j++)
		{
			if (s[j] < 'a')
			{
				a[i][j] = s[j] - 'A';
			}
			else
			{
				a[i][j] = s[j] - 'A' - 6;
			}
			
		}
	}

	ret = a[0][0];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			v.push_back(i * 100 + j);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int d = 0; d < 4; d++)
			{
				int ny = i + dy[d], nx = j + dx[d];

				if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

				int dist = abs(a[i][j] - a[ny][nx]);
				if (dist <= t)
				{
					if (a[ny][nx] > a[i][j])
					{
						b[i * 100 + j][ny * 100 + nx] = dist * dist;
					}
					else
					{
						b[i * 100 + j][ny * 100 + nx] = 1;
					}
				}
			}
		}
	}

	for (int k : v)
	{
		for (int i : v)
		{
			for (int j : v)
			{
				b[i][j] = min(b[i][j], b[i][k] + b[k][j]);
			}
		}
	}

	for (int i : v)
	{
		if (d >= b[0][i] + b[i][0])
		{
			ret = max(ret, a[i / 100][i % 100]);
		}
	}

	cout << ret << "\n";

	return 0;
}