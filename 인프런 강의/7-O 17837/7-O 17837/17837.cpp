#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct mal
{
	int y;
	int x;
	int dir;
};

const int dy[] = { 0, 0, -1, 1 };
const int dx[] = { 1, -1, 0, 0 };
int n, k, a[14][14], y, x, d;
vector<int> mals[14][14];
vector<mal> status;

void go(int y, int x, int dir, int i)
{
	int ny = y + dy[dir], nx = x + dx[dir];
	if (ny < 0 || ny >= n || nx < 0 || nx >= n || a[ny][nx] == 2)
	{
		status[i].dir ^= 1;
		ny = y + dy[status[i].dir], nx = x + dx[status[i].dir];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n || a[ny][nx] == 2) return;
	}

	vector<int>& here_v = mals[y][x];
	vector<int>& next_v = mals[ny][nx];
	vector<int>::iterator pos = find(here_v.begin(), here_v.end(), i);

	if (a[ny][nx] == 1)
	{
		reverse(pos, here_v.end());
	}

	for (vector<int>::iterator itr = pos; itr != here_v.end(); itr++)
	{
		next_v.push_back(*itr);
		status[*itr].y = ny;
		status[*itr].x = nx;
	}
	here_v.erase(pos, here_v.end());
	return;
}

bool check()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) 
		{
			if (mals[i][j].size() >= 4) 
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < k; i++)
	{
		cin >> y >> x >> d;
		y--, x--, d--;
		mals[y][x].push_back(i);
		status.push_back({ y, x, d });
	}

	int cnt = 0;
	bool bIsFour = false;
	while (cnt <= 1000)
	{
		cnt++;

		for (int i = 0; i < status.size(); i++)
		{
			int y1 = status[i].y;
			int x1 = status[i].x;
			int dir = status[i].dir;

			go(y1, x1, dir, i);

			if (check())
			{
				bIsFour = true;
				break;
			}
		}
		if (bIsFour) break;
	}

	bIsFour ? cout << cnt << "\n":cout << -1 << "\n";

	return 0;
}