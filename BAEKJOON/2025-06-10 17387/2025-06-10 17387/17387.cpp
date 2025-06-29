#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

struct Cordi
{
	int x1, y1, x2, y2;
};

int ccw(int x1, int y1, int x2, int y2, int x3, int y3)
{
	ll def = 1LL * (x2 - x1) * (y3 - y1) - 1LL * (y2 - y1) * (x3 - x1);

	if (def < 0) return -1;
	if (def > 0) return 1;
	return 0;
}

bool isCross(Cordi a, Cordi b)
{
	int A = ccw(a.x1, a.y1, a.x2, a.y2, b.x1, b.y1);
	int B = ccw(a.x1, a.y1, a.x2, a.y2, b.x2, b.y2);
	int C = ccw(b.x1, b.y1, b.x2, b.y2, a.x1, a.y1);
	int D = ccw(b.x1, b.y1, b.x2, b.y2, a.x2, a.y2);

	if (A * B <= 0 && C * D <= 0)
	{
		if (max(a.x1, a.x2) < min(b.x1, b.x2)) return false;
		if (max(b.x1, b.x2) < min(a.x1, a.x2)) return false;
		if (max(a.y1, a.y2) < min(b.y1, b.y2)) return false;
		if (max(b.y1, b.y2) < min(a.y1, a.y2)) return false;
		return true;
	}
	return false;
}

int main()
{
	Cordi a, b;
	cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
	cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;

	cout << (isCross(a, b) ? 1 : 0) << "\n";

	return 0;
}