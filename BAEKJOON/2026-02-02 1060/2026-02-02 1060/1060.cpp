#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

typedef long long ll;

struct Element
{
	ll value, cnt;

	bool operator>(const Element& other) const
	{
		if (cnt != other.cnt) return cnt > other.cnt;
		return value > other.value;
	}
};

int l, n;
vector<int> arr;
priority_queue<Element, vector<Element>, greater<Element>> pq;

void push_num(ll left, ll right, ll val)
{
	if (val <= left || val >= right) return;

	ll cnt = (val - left) * (right - val) - 1;
	pq.push({ val, cnt });
}

int main()
{
	cin >> l;
	arr.assign(l, 0);

	for (int i = 0; i < l; i++)
	{
		cin >> arr[i];
	}

	cin >> n;

	sort(arr.begin(), arr.end());

	for (const int num : arr)
	{
		pq.push({ 1LL * num, 0 });
	}

	int prev = 0;
	for (const int num : arr)
	{
		int left = prev + 1;
		int right = num - 1;

		if (left > right)
		{
			prev = num;
			continue;
		}

		for (int i = 0; i < n && left + i <= right - i; i++)
		{
			push_num(prev, num, left + i);
			if (left + i != right - i) push_num(prev, num, right - i);
		}

		prev = num;
	}

	int print = 0;
	ll infinity_num = arr.back() + 1;
	while (print < n)
	{
		if (pq.empty())
		{
			cout << infinity_num++ << " ";
			print++;
			continue;
		}

		Element e = pq.top();
		pq.pop();

		cout << e.value << " ";
		print++;
	}

	return 0;
}