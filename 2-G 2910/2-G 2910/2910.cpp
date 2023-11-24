#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int n, c, val;
vector<pair<int, int>> ret;
map<int, int> m, m_first;

bool compare(const pair<int, int>& x, const pair<int, int>& y) {

	if (x.second == y.second) {
		return m_first[x.first] < m_first[y.first];
	}

	return x.second > y.second;
}

int main() {

	cin >> n >> c;
	
	for (int i = 0; i < n; i++) {
		cin >> val; m[val]++;
		if (m_first[val] == 0) m_first[val] = i + 1;
	}

	for (auto a : m) {
		ret.push_back({ a.first, a.second });
	}

	sort(ret.begin(), ret.end(), compare);
	
	for (auto v : ret) {
		for (int i = 0; i < v.second; i++) {
			cout << v.first << " ";
		}
	}

	return 0;
}