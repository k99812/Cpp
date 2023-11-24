#include<string>
#include<iostream>
#include<vector>

using namespace std;

string input;
int lvow, rvow;

int is_vowel(int input) {
	return (input == 'a' || input == 'e' || input == 'i' || input == 'o' || input == 'u');
}

int main() {

	while (true) {
		cin >> input;
		if (input == "end") break;

		bool is_in_vowel = false, is_accept = true;
		lvow = 0, rvow = 0;
		
		int idx, prev;
		prev = -1;

		for (int i = 0; i < input.length(); i++) {
			idx = input[i];
			if (is_vowel(idx)) lvow++, rvow = 0, is_in_vowel = true;
			else lvow = 0, rvow++;
			if (lvow == 3 || rvow == 3) is_accept = false;
			if (i >= 1 && prev == idx && idx != 'e' && idx != 'o') is_accept = false;
			prev = idx;
		}
		if (!is_in_vowel) is_accept = false;
		if (is_accept) cout << "<" << input << "> is acceptable.\n";
		else cout << "<" << input << "> is not acceptable.\n";
	}

	return 0;
}