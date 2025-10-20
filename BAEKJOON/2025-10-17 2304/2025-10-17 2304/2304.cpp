#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct Cordi
{
	int y, x;

	bool operator<(const Cordi& other) const
	{
		if (x != other.x) return x < other.x;
		return y > other.y;
	}
};

int n;
vector<Cordi> arr;

int main()
{
	cin >> n;

	arr = vector<Cordi>(n);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].x >> arr[i].y;
	}

	sort(arr.begin(), arr.end());



	return 0;
}