#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int n, a[1000004], ret[1000004];
vector<int>  s;

int main() {

	cin >> n;

	fill(&ret[0], &ret[1000003], -1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		while (s.size() && a[s.back()] < a[i]) {
			ret[s.back()] = a[i]; s.pop_back();
		}
		s.push_back(i);
	}
	for (int i = 0; i < n; i++) cout << ret[i] << " ";
	return 0;
}