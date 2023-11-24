#include<string>
#include<iostream>
#include<tuple>
#include<algorithm>
#include<queue>

using namespace std;

const int INF = 987654321;
const int max_n = 1004;
int r, c, j_visited[max_n][max_n], f_visited[max_n][max_n], ret;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
char map[max_n][max_n];
string s;
pair<int, int> jh;
queue<pair<int, int>> q;

int main() {
	cin >> r >> c;
	fill(&f_visited[0][0], &f_visited[max_n - 1][max_n], INF);

	for (int i = 0; i < r; i++) {
		cin >> s;
		for (int j = 0; j < c; j++) {
			map[i][j] = s[j];
			if (map[i][j] == 'J') jh = { i, j };
			else if (map[i][j] == 'F') { q.push({ i,j }); f_visited[i][j] = 1; }
		}
	}

	while (q.size()) {
		int y, x;
		tie(y, x) = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
			if (map[ny][nx] == '#') continue;
			if (f_visited[ny][nx] != INF) continue;
			f_visited[ny][nx] = f_visited[y][x] + 1;
			q.push({ ny, nx });
		}
	}

	q.push(jh);
	j_visited[jh.first][jh.second] = 1;
	while (q.size()) {
		int y, x;
		tie(y, x) = q.front(); q.pop();
		if (x == c - 1 || y == r - 1 || x == 0 || y == 0) {
			ret = j_visited[y][x];
			break;
		}
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
			if (map[ny][nx] == '#') continue;
			if (j_visited[ny][nx]) continue;
			if (j_visited[y][x] + 1 >= f_visited[ny][nx]) continue;
			j_visited[ny][nx] = j_visited[y][x] + 1; 
			q.push({ ny, nx });
		}
	}

	ret == 0 ? cout <<"IMPOSSIBLE \n" : cout << ret << "\n";
	return 0;
}