#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

int n;
ll l, w, h;

bool check(double mid)
{
	ll cnt_l = l / mid;
	ll cnt_w = w / mid;
	ll cnt_h = h / mid;

	double total = (double)cnt_l * cnt_w * cnt_h;

	return total >= n;
}

int main()
{
	cin >> n >> l >> w >> h;

	double left = 0.0f, right = 1e9, ret = 0.0f;

    for (int i = 0; i < 100; i++)
    {
        double mid = (left + right) / 2;

        if (check(mid))
        {
            ret = mid;
            left = mid; 
        }
        else
        {
            right = mid;
        }
    }

    cout.precision(30);
    cout << left << "\n";

	return 0;
}