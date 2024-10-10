#include<iostream>
#include<algorithm>

using namespace std;

int n, m, a[1004], dp[1004][34][2];

int go(int time, int move, int tree)
{
	//�������
	if (move > m) return -1e9;
	if (time == n) return 0;

	//�޸����̼�
	int& ret = dp[time][move][tree];
	if (ret) return ret;

	//����
	return ret = max(go(time + 1, move + 1, tree ^ 1), go(time + 1, move, tree)) + (a[time] - 1 == tree);
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++) cin >> a[i];

	cout << max(go(0, 1, 1), go(0, 0, 0)) << "\n";

	return 0;
}