#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

vector<char> word;
string str;
int n, ret = 0;

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> str;

		word.clear();

		for (char c : str) {
			if (word.size() && word.back() == c) word.pop_back(); 
			else word.push_back(c);
		}

		if (!word.size()) ret++;
	}

	cout << ret;

	return 0;
}