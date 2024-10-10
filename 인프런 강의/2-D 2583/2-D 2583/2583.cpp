#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
#include<tuple>
#include<vector>

using namespace std;

const int Max_Num = 101;
int m, n, k, left_x, left_y, right_x, right_y, map[Max_Num][Max_Num], visited[Max_Num][Max_Num], ret = 0, sum;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
queue <pair<int, int>> q;
vector<int> nums;

void bfs(int y, int x) {
	visited[y][x] = 1;
	q.push({ y, x });
	sum = 1;

	while (q.size()) {
		int ty, tx, ny, nx;
		tie(ty, tx) = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			ny = ty + dy[i]; nx = tx + dx[i];
			if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
			if (map[ny][nx] == 0) continue;
			if (visited[ny][nx]) continue;
			q.push({ ny, nx }); visited[ny][nx] = visited[ty][tx] + 1; sum++;
		}
	}
	nums.push_back(sum);
}

int dfs(int y, int x) {
	visited[y][x] = 1;
	int ny, nx, cnt = 1;

	for (int i = 0; i < 4; i++) {
		ny = y + dy[i]; nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
		if (map[ny][nx] == 0) continue;
		if (visited[ny][nx]) continue;
		cnt += dfs(ny, nx);
	}
	return cnt;
}

int main() {

	cin >> m >> n >> k;

	fill(&map[0][0], &map[Max_Num - 1][Max_Num], 1);

	while (k--) {
		cin >> left_x >> left_y >> right_x >> right_y;
		for (int i = left_y; i < right_y; i++) {
			for (int j = left_x; j < right_x; j++) {
				map[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0) continue;
			if (visited[i][j]) continue;
			//dfs//nums.push_back(dfs(i, j)); ret++;
			 bfs(i, j); ret++;
		}
	}

	sort(nums.begin(), nums.end());

	cout << ret << "\n";
	for_each(nums.begin(), nums.end(), [](const int& a) { cout << a << " "; });

	return 0;
}