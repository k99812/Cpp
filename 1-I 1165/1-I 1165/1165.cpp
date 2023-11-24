#include<algorithm>
#include<iostream>
#include<map>
#include<string>

using namespace std;

int n, m;
string str, problem;
map<string, int> si;
map<int, string> is;


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	//포켓몬 입력
	for (int i = 1; i <= n; i++) {
		cin >> str;
		si[str] = i;
		is[i] = str;
	}

	//문제 입력
	for (int i = 0; i < m; i++) {
		cin >> problem;

		if (isalpha(problem.front())) {
			cout << si[problem] << "\n";
		}
		else {
			cout << is[atoi(problem.c_str())] << "\n";
		}
	}

	/*
	for (int i = 0; i < n; i++) {
		cout << "input i : " << input[i].first +1<< " str : " << input[i].second;
		cout << "\n";
	}*/

	return 0;
}