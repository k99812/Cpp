#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>

using namespace std;

const int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int n, home;

bool bfs(const pair<int, int>& post, const vector<vector<char>>& map, const vector<vector<int>>& dist, vector<vector<int>>& visited, const int& low, const int& hight)
{
	fill(visited.begin(), visited.end(), vector<int>(n));
	queue<pair<int, int>> q;
	q.push(post);
	visited[post.first][post.second] = 1;
	int cnt = 0;

	while (q.size())
	{
		int y = q.front().first, x = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int ny = y + dy[i], nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (visited[ny][nx] || dist[ny][nx] < low || dist[ny][nx] > hight) continue;
			if (map[ny][nx] == 'K')
			{
				cnt++;
				if (cnt == home) return true;
			}

			visited[ny][nx] = true;
			q.push({ ny, nx });
		}
	}

	return false;
}

int main()
{
	cin >> n;

	vector<vector<char>> map(n);
	for (vector<char>& v : map) v.resize(n);

	vector<vector<int>> dist(n);
	for (vector<int>& v : dist) v.resize(n);

	vector<vector<int>> visited(n);
	vector<int> unique_dist;
	pair<int, int> post;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
		{
			map[i][j] = s[j];
			if (s[j] == 'P') post = { i, j };
			else if (s[j] == 'K') home++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> dist[i][j];
			unique_dist.push_back(dist[i][j]);
		}
	}

	sort(unique_dist.begin(), unique_dist.end());
	unique_dist.erase(unique(unique_dist.begin(), unique_dist.end()), unique_dist.end());

	int ret = INT32_MAX;
	int first = 0, second = 0;

	while (second < unique_dist.size())
	{
		while (true) 
		{
			if (unique_dist[first] <= dist[post.first][post.second] && dist[post.first][post.second] <= unique_dist[second])
			{
				if (bfs(post, map, dist, visited, unique_dist[first], unique_dist[second]))
				{
					ret = min(ret, unique_dist[second] - unique_dist[first]);
					first++;
				}
				else
				{
					break;
				}
			}
			else
			{
				break;
			}
		}
		
		second++;
	}

	cout << ret << "\n";

	return 0;
}