#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int INF = 1e9;

int n;
vector<int> arr;

int main()
{
	cin >> n;

	arr.assign(n + 1, 0);

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	vector<int> cnt(n + 1, 0);        
	vector<int> nearest(n + 1, 0);    
	vector<int> min_dist(n + 1, INF); 
	vector<int> s;

	for (int i = 1; i <= n; i++)
	{
		while (s.size() && arr[s.back()] <= arr[i])
		{
			s.pop_back();
		}

		cnt[i] += s.size();

		if (s.size())
		{
			int dist = i - s.back();
			if (dist < min_dist[i])
			{
				min_dist[i] = dist;
				nearest[i] = s.back();
			}
		}

		s.push_back(i);
	}

	while (s.size()) s.pop_back();

	for (int i = n; i >= 1; i--)
	{
		while (s.size() && arr[s.back()] <= arr[i])
		{
			s.pop_back();
		}

		cnt[i] += s.size();

		if (s.size())
		{
			int dist = s.back() - i;
			if (dist < min_dist[i])
			{
				min_dist[i] = dist;
				nearest[i] = s.back();
			}
			else if (dist == min_dist[i] && s.back() < nearest[i])
			{
				nearest[i] = s.back();
			}
		}

		s.push_back(i);
	}

	for (int i = 1; i <= n; i++)
	{
		if (cnt[i] == 0)
		{
			cout << 0 << "\n";
		}
		else
		{
			cout << cnt[i] << " " << nearest[i] << "\n";
		}
	}

	return 0;
}