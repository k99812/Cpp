#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;

int main()
{
	cin >> n;

	vector<int> a(n), b(n);

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), [](const int& A, const int& B)
	{
		return A > B;
	});


	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		ret += a[i] * b[i];
	}

	cout << ret << "\n";

	return 0;
}