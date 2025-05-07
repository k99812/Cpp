#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n;
vector<vector<int>> graph, student;

struct Info
{
	int like_cnt,
		empty_cnt,
		y,
		x;
};

Info searchPos(int y, int x, int target)
{
	int likeCnt = 0, emptyCnt = 0;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i], nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;

		if (graph[ny][nx])
		{
			if (find(student[target].begin(), student[target].end(), graph[ny][nx]) != student[target].end())
			{
				likeCnt++;
			}
		}
		else
		{
			emptyCnt++;
		}
	}

	return { likeCnt, emptyCnt, y, x };
}

pair<int, int> findCordi(int target)
{
	vector<Info> temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (graph[i][j]) continue;

			temp.push_back(searchPos(i, j, target));
		}
	}

	sort(temp.begin(), temp.end(), [](const Info& a, const Info& b)
	{
		if (a.like_cnt != b.like_cnt) return a.like_cnt > b.like_cnt;
		if (a.empty_cnt != b.empty_cnt) return a.empty_cnt > b.empty_cnt;
		if (a.y != b.y) return a.y < b.y;
		return a.x < b.x;
	});

	return { temp[0].y, temp[0].x };
}

int getPoint(int y, int x)
{
	int cnt = 0, now = graph[y][x];

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i], nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;

		int target = graph[ny][nx];
		if (find(student[now].begin(), student[now].end(), target) != student[now].end())
		{
			cnt++;
		}
	}

	return cnt ? pow(10, cnt - 1) : 0;
}

int main()
{
	cin >> n;

	int max_n = pow(n, 2);
	student = vector<vector<int>>(max_n + 1, vector<int>(4));
	graph = vector<vector<int>>(n, vector<int>(n));


	for (int i = 0; i < max_n; i++)
	{
		int target;
		cin >> target;

		for (int& i : student[target])
		{
			cin >> i;
		}

		pair<int, int> pos = findCordi(target);
		graph[pos.first][pos.second] = target;
	}

	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ret += getPoint(i, j);
		}
	}

	cout << ret << "\n";

	return 0;
}