#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int n, t, r, root;
vector<int> tree[54];

int dfs(int start) {
	int ret = 0;
	int child = 0;
	for (int i : tree[start]) {
		if (i == r) continue;
		ret += dfs(i);
		child++;
	}
	if (child == 0) return 1;
	return ret;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> t;
		if (t ==  -1) root = i;
		else tree[t].push_back(i);
	}
	cin >> r;
	if (r == root) {
		cout << 0 << "\n"; return 0;
	}
	cout << dfs(root) << "\n";
	return 0;
}