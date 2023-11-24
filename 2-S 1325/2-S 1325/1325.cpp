#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int n, m, a, b, mx = 0, visited[10004], dp[10004];
vector<int> v[10004];
vector<pair<int, int>> v2;
vector<int> ret;

int dfs(int start) {
	visited[start] = 1;
	int child = 0;
	int ret = 0;

	for (int a : v[start]) {
		if (visited[a]) continue;
		ret += dfs(a);
		child++;
	}
	if (child == 0) return 0;
	else return ret + child;
}

int main() {

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		fill(&visited[0], &visited[10003], 0);
		dp[i] = dfs(i);
		mx = max(dp[i], mx);
	}

	for (int i = 1; i <= n; i++) {
		if (dp[i] == mx) cout << i << " ";
	}

	//원래 내코드
	/*for (int i = 1; i <= n; i++) {
		fill(&visited[0], &visited[10003], 0);
		int temp = dfs(i);
		v2.push_back({ i, temp });
		mx = max(mx, temp);
	}

	for (pair<int, int> p : v2) {
		if (p.second == mx) {
			ret.push_back(p.first);
		}
	}
	sort(ret.begin(), ret.end());
	for_each(ret.begin(), ret.end(), [](const int& a) { cout << a << " "; });*/

	return 0;
}
