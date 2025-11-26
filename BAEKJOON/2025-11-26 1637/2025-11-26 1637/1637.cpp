#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

struct Info
{
	ll a, b, c;
};

int n;
vector<Info> arr;

int main()
{
	cin >> n;

	arr = vector<Info>(n);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].a >> arr[i].c >> arr[i].b;
	}
	
	return 0;
}