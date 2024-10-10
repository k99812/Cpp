#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

long long A, B, C;
long long ret;

long long multi(const long long &a,const long long &b) {

	if (b == 1) { return a % C; }

	ret = multi(a, b / 2);
	ret = (ret * ret) % C;

	if (b % 2) ret = (ret * a) % C;
	return ret;
}

int main() {

	cin >> A >> B >> C;

	cout << multi(A, B);

	return 0;
}