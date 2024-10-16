#include<iostream>
#include<algorithm>
#include<queue>

#define MAX_NUM 1000 + 4

using namespace std;

struct Data
{
	int y,
		x,
		bWallIsDestroy;
};

int n, m, a[MAX_NUM][MAX_NUM], visited[MAX_NUM][MAX_NUM][2];

void bfs()
{
	queue<Data> q;
	q.push({ 0,0,0 });
	visited[0][0][0] = 1;

	while (q.size())
	{
		int y = q.front().y, x = q.front().x, bWallIsDestroy = q.front().bWallIsDestroy;
		q.pop();
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}

	return 0;
}