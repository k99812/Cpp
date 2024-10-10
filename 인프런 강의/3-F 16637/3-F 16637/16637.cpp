#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int n, ret = -98792498;
string s;
vector<int> num;
vector<char> oper_str;

int oper(int a, int b, char c) {
	if (c == '+') return a + b;
	if (c == '-') return a - b;
	if (c == '*') return a * b;
}

void solution(int here, int val) {
	if (here == num.size() - 1) {
		ret = max(ret, val);
		return;
	}

	solution(here + 1, oper(val, num[here + 1], oper_str[here]));
	if (here + 2 <= num.size() - 1) {
		int temp = oper(num[here + 1], num[here + 2], oper_str[here + 1]);
		solution(here + 2, oper(val, temp, oper_str[here]));
	}
}

int main() {
	cin >> n;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (isdigit(s[i])) num.push_back(s[i] - '0');
		else oper_str.push_back(s[i]);
	}
	solution(0, num[0]);
	cout << ret << "\n";
	return 0;
}