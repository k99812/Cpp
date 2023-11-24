#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>

using namespace std;

int n, k, psum[100001], temp, ret = -100000;

int main() {
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> temp;

		psum[i] = psum[i - 1] + temp;
	}

	for (int i = k; i <= n; i++) {
		ret = max(ret, psum[i] - psum[i - k]);
	}

	cout << ret;

	return 0;
}