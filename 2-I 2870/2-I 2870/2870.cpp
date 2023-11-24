#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int n;
string s, token;
vector<string> ret;

void push_token() {
	while (true) {
		if (token.length() && token.front() == '0') token.erase(token.begin());
		else break;
	}
	if (!token.length()) token = '0';
	ret.push_back(token);
	token = "";
}

bool cmp(string a, string b) {
	if (a.length() == b.length()) return a < b;
	return a.length() < b.length();
}

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s;
		token = "";

		for (int j = 0; j < s.length(); j++) {
			if (isdigit(s[j])) token += s[j];
			else if (token.length() && !isdigit(s[j])) push_token();
		}
		if (token.length()) push_token();
	}
	sort(ret.begin(), ret.end(), cmp);
	for_each(ret.begin(), ret.end(), [](const auto& a) { cout << a << "\n"; });
	return 0;
}