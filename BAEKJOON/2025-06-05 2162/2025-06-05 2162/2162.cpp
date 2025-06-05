#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

struct Cordi
{
	int x1, y1, x2, y2;
};

int n;
vector<int> parent;
vector<Cordi> v;

int getRoot(int num)
{
	if (num == parent[num]) return parent[num];
	return parent[num] = getRoot(parent[num]);
}

void unionParent(int a, int b)
{
	int parent_a = getRoot(a), parent_b = getRoot(b);

	if (parent_a != parent_b)
	{
		if (parent_a < parent_b)
		{
			parent[parent_b] = parent_a;
		}
		else
		{
			parent[parent_a] = parent_b;
		}

	}
}

int ccw(int x1, int y1, int x2, int y2, int x3, int y3)
{
	long long val = 1LL * (x2 - x1) * (y3 - y1) - 1LL * (y2 - y1) * (x3 - x1);
	if (val > 0) return 1;
	if (val < 0) return -1;
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
	cin >> n;

	v = vector<Cordi>(n);
	parent = vector<int>(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i].x1 >> v[i].y1 >> v[i].x2 >> v[i].y2;

		parent[i] = i;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (isCross(v[i], v[j]))
			{
				unionParent(i, j);
			}
		}
	}

	map<int, int> groupCnt;
	for (int i = 0; i < n; i++)
	{
		groupCnt[getRoot(i)]++;
	}

	int maxGroup = 0;
	for (const pair<int, int>& p : groupCnt)
	{
		maxGroup = max(maxGroup, p.second);
	}

	cout << groupCnt.size() << "\n" << maxGroup << "\n";

	return 0;
}