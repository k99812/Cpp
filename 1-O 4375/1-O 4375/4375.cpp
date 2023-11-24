#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int n;
bool isFind = false;
int ret;

int main() {

	while (cin >> n) {
		long long temp = 1;
		ret = 1;
		while (!isFind) {
			if (temp % n == 0) {

				cout << ret << "\n";
				isFind = true;
			}
			else {
				temp = (temp * 10) + 1;
				temp %= n;
				ret++;
				cout <<" else ret : "<< ret << "\n";
			}
		}
		isFind = false;
	}

	return 0;
}