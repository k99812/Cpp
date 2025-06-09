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
	ll angle = 1LL * (x2 - x1) * (y3 - y1) - 1LL * (y2 - y1) * (x3 - x1);

	if (angle < 0) return -1;
	if (angle > 0) return 1;
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

bool onStright(Cordi dot, ll x, ll y)
{
	return min(dot.x1, dot.x2) <= x && x <= max(dot.x1, dot.x2) 
		&& min(dot.y1, dot.y2) <= y && y <= max(dot.y1, dot.y2);
}

pair<double, double> getCrossPoint(Cordi a, Cordi b)
{
	ll p = (a.x1 - a.x2) * (b.y1 - b.y2) - (a.y1 - a.y2) * (b.x1 - b.x2);
	double px = ((a.x1 * a.y2 - a.y1 * a.x2) * (b.x1 - b.x2) - (a.x1 - a.x2) * (b.x1 * b.y2 - b.y1 * b.x2)) / (double)p;
	double py = ((a.x1 * a.y2 - a.y1 * a.x2) * (b.y1 - b.y2) - (a.y1 - a.y2) * (b.x1 * b.y2 - b.y1 * b.x2)) / (double)p;

	return { px, py };
}

int main()
{
	Cordi L1, L2;
	cin >> L1.x1 >> L1.y1 >> L1.x2 >> L1.y2;
	cin >> L2.x1 >> L2.y1 >> L2.x2 >> L2.y2;

	if (!isCross(L1, L2))
	{
		cout << 0 << "\n";
		return 0;
	}

	cout << 1 << "\n";

	ll dx1 = L1.x2 - L1.x1, dy1 = L1.y2 - L1.y1;
	ll dx2 = L2.x2 - L2.x1, dy2 = L2.y2 - L2.y1;
	ll cross = dx1 * dy2 - dx2 * dy1;

	if (cross == 0)
	{
		vector<pair<ll, ll>> point = {
			{ L1.x1, L1.y1 }, { L1.x2, L1.y2 }, { L2.x1, L2.y1 }, { L2.x2, L2.y2 }
		};

		sort(point.begin(), point.end());

		for (const pair<ll, ll>& i : point)
		{
			if (onStright(L1, i.first, i.second) && onStright(L2, i.first, i.second))
			{
				cout << i.first << " " << i.second << "\n";
				break;
			}
		}
	}
	else
	{
		pair<double, double> ret = getCrossPoint(L1, L2);
		cout << fixed;
		cout.precision(9);
		cout << ret.first << " " << ret.second << "\n";
	}

	return 0;
}