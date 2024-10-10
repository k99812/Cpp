#include<iostream>
#include<algorithm>

using namespace std;

const int n = 18;
float a, b, dp[20][20][20];
bool isP[24];

float go(int x, int y, int idx)
{
	if (idx == n) return isP[x] || isP[y] ? 1.0 : 0.0;

	float& ret = dp[x][y][idx];
	if (ret > 0.5f) return ret;

	ret = 0.0f;
	ret += go(x, y, idx + 1) * (1 - a) * (1 - b);
	ret += go(x + 1, y, idx + 1) * a * (1 - b);
	ret += go(x, y + 1, idx + 1) * (1 - a) * b;
	ret += go(x + 1, y + 1, idx + 1) * a * b;
	return ret;
}

void era() {

	fill(&isP[0], &isP[20], 1);
	isP[0] = 0; isP[1] = 0;

	for (int i = 2; i <= 20; i++) 
	{
		if (!isP[i]) continue;
		for (int j = i + i; j <= 20; j += i) 
		{
			isP[j] = 0;
		}
	}
}

int main()
{
	cin >> a >> b;
	a /= 100, b /= 100;
	era();
	fill(&dp[0][0][0], &dp[19][19][20], -1);

	cout << go(0,0,0) << "\n";

	return 0;
}