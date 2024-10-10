#include<algorithm>
#include<iostream>

using namespace std;

int A, B, C, e, f, T[101], ret;

int main() {

	ret = 0;

	fill(&T[0], &T[101], 0);

	cin >> A >> B >> C;

	for (int i = 0; i < 3; i++) {
		cin >> e >> f;
		cout << "\n" << "e, f : " << e << f << "\n";
		for (int j = e; j < f; j++) {
			cout << "e : " << e;
			T[j]++;
		}
		cout << "\n";
	}
	
	//for_each(&T[0], &T[104], [](int& y) { cout << y << " "; });
	cout << "\n";

	for (int x = 1; x < 100; x++) {
		cout << T[x] << " ";
		switch (T[x]) {
		case 0:
			continue;
		case 1:
			ret += A;
			break;
		case 2:
			ret += 2 * B;
			break;
		case 3:
			ret += 3 * C;
			break;
		}

	}

	cout << ret << "\n";
}