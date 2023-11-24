#include<iostream>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

int n, m;
string a, b;

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {

		cin >> m;
		map<string, int> m1;

		for (int j = 0; j < m; j++) {
			cin >> a >> b;
			m1[b]++;
		}
		long long ret = 1;
		for (auto a : m1) {
			ret *= ((long long)a.second + 1);
		}
		ret--;

		cout << ret << "\n";
	}

	return 0;
}