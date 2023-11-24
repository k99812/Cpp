#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

const int max_n = 10;
int map[max_n][max_n], visited[max_n][max_n], n, m, ret;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
vector<pair<int, int>> virusList, wallList;

void dfs(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i], nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (map[ny][nx] == 1) continue;
		if (visited[ny][nx] == 1) continue;
		visited[ny][nx] = 1;
		dfs(ny, nx);
	}
	return;
}

int solve() {
	fill(&visited[0][0], &visited[max_n - 1][max_n], 0);
	for (pair<int, int> p : virusList) {
		visited[p.first][p.second] = 1;
		dfs(p.first, p.second);
	}

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0 && !visited[i][j]) cnt++;
		}
	}
	return cnt;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) wallList.push_back({ i, j });
			else if (map[i][j] == 2) virusList.push_back({ i, j });
		}
	}

	for (int i = 0; i < wallList.size(); i++) {
		for (int j = 0; j < i; j++) {
			for (int k = 0; k < j; k++) {
				map[wallList[i].first][wallList[i].second] = 1;
				map[wallList[j].first][wallList[j].second] = 1;
				map[wallList[k].first][wallList[k].second] = 1;
				ret = max(ret, solve());
				map[wallList[i].first][wallList[i].second] = 0;
				map[wallList[j].first][wallList[j].second] = 0;
				map[wallList[k].first][wallList[k].second] = 0;
			}
		}
	}
	cout << ret << "\n";
	return 0;
}