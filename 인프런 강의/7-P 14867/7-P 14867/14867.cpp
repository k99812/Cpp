#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<tuple>

using namespace std;

int a, b, c, d;
map<pair<int, int>, int> m;
queue<pair<int, int>> q;

void enqeue(int x, int y, int d)
{
	if (m[{x, y}]) return;
	m[{x, y}] += d + 1;
	q.push({ x, y });
}

int bfs(int x, int y)
{
	m[{x, y}] = 1;
	q.push({ x, y });
	while (q.size())
	{
		tie(x, y) = q.front();
		q.pop();

		enqeue(a, y, m[{x, y}]);
		enqeue(x, b, m[{x, y}]);
		enqeue(0, y, m[{x, y}]);
		enqeue(x, 0, m[{x, y}]);
		enqeue(min(x + y, a), max(0, x + y - a), m[{x, y}]);
		enqeue(max(0, y + x - b), min(b, y + x), m[{x, y}]);
	}
	if (!m[{c, d}]) return -1;
	return m[{c, d}] - 1;
}

int main()
{
	cin >> a >> b >> c >> d;

	cout << bfs(0, 0) << "\n";

	return 0;
}