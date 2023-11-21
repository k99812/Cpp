#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int INF = 1e8;
int n, k, cnt, visited[104];
vector<int> v;

int main()
{
	cin >> n >> k;
	vector<int> a(k);

	for (int i = 0; i < k; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < k; i++)
	{
		if (!visited[a[i]])
		{
			if (v.size() == n)
			{
				int last_idx = 0, pos;
				for (int t : v)
				{
					int here_idx = INF;
					for (int j = i + 1; j < k; j++)
					{
						if (a[j] == t)
						{
							here_idx = j; break;
						}
					}
					if (last_idx < here_idx)
					{
						last_idx = here_idx;
						pos = t;
					}
				}
				visited[pos] = 0;
				v.erase(find(v.begin(), v.end(), pos));
				cnt++;
			}

			v.push_back(a[i]); visited[a[i]] = 1;
		}
	}

	cout << cnt << "\n";

	return 0;
}