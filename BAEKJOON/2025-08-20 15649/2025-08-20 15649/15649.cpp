#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;
vector<int> nums;
vector<bool> visited;

void combi(int idx)
{
	if (idx == m)
	{
		for (const int& num : nums)
		{
			cout << num << " ";
		}
		cout << "\n";

		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (visited[i]) continue;
		nums[idx] = i;
		visited[i] = true;
		combi(idx + 1);
		visited[i] = false;
	}
}

int main()
{
	cin >> n >> m;

	visited = vector<bool>(n + 1);
	nums = vector<int>(m);

	combi(0);

	return 0;
}