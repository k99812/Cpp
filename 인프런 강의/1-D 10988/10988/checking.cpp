#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string input;
bool isSame = false;

int main() {
	cin >> input;

	isSame = input.front() == input.back();

	if (isSame) {
		for (int i = 1; i < input.size() / 2; i++) {
			if (isSame) {
				isSame = *(input.begin() + i) == *((input.end() - 1) - i);
			}
			else break;
		}
	}
	
	cout << (int)isSame;

	return 0;
}