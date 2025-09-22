#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

int n;
vector<pair<ll, ll>> cordi;

ll getDist(const pair<ll, ll>& a, const pair<ll, ll>& b)
{
    ll dx = a.first - b.first;
    ll dy = a.second - b.second;
    return dx * dx + dy * dy;
}

ll go(int l, int r)
{
    int size = r - l + 1;
    if (size <= 3)
    {
        ll ret = LLONG_MAX;
        for (int i = l; i <= r; i++)
        {
            for (int j = i + 1; j <= r; j++)
            {
                ret = min(ret, getDist(cordi[i], cordi[j]));
            }
        }
        return ret;
    }

    int mid = (l + r) / 2;
    ll dist1 = go(l, mid);
    ll dist2 = go(mid + 1, r);
    ll dist = min(dist1, dist2);

    vector<pair<ll, ll>> v;
    for (int i = l; i <= r; i++)
    {
        ll dx = cordi[i].first - cordi[mid].first;
        if (dx * dx < dist)
        {
            v.push_back(cordi[i]);
        }
    }

    sort(v.begin(), v.end(), [](const pair<ll, ll>& a, const pair<ll, ll>& b)
    {
        return a.second < b.second;
    });

    for (int i = 0; i < (int)v.size(); i++)
    {
        for (int j = i + 1; j < (int)v.size(); j++)
        {
            ll dy = v[j].second - v[i].second;
            if (dy * dy >= dist) break;
            dist = min(dist, getDist(v[i], v[j]));
        }
    }

    return dist;
}

int main()
{
	cin >> n;

	cordi = vector<pair<ll, ll>>(n);

	for (int i = 0; i < n; i++)
	{
		cin >> cordi[i].first >> cordi[i].second;
	}

	sort(cordi.begin(), cordi.end());

	ll ret = go(0, n - 1);
	cout << ret << "\n";

	return 0;
}