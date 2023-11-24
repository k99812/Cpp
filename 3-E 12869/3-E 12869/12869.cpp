#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<tuple>

using namespace std;

int n, a[3], visited[64][64][64];
int AD[6][3] = { 
	{9, 3, 1},
	{9, 1, 3},
	{3, 9, 1},
	{3, 1, 9},
	{1, 9, 3},
	{1, 3, 9}
};
struct A {
	int a, b, c;
};

queue<A> q;
int solve(int a, int b, int c) {
	visited[a][b][c] = 1;
	q.push({ a,b,c });
	while (q.size()) {
		int ta = q.front().a, tb = q.front().b, tc = q.front().c;
		q.pop();
		if (visited[0][0][0]) break;
		for (int i = 0; i < 6; i++) {
			int na = max(0, ta - AD[i][0]);
			int nb = max(0, tb - AD[i][1]);
			int nc = max(0, tc - AD[i][2]);
			if (visited[na][nb][nc]) continue;
			visited[na][nb][nc] = visited[ta][tb][tc] + 1;
			q.push({ na, nb, nc });
		}
	}
	return visited[0][0][0] - 1;
}

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cout << solve(a[0], a[1], a[2]) << "\n";

	return 0;
}