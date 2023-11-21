#include<iostream>
#include<algorithm>

using namespace std;

int n, a[1004], ret = 1, cnt[1004], pre[1004], idx;

void go(int idx)
{
	if (idx == -1) return;
	go(pre[idx]);
	cout << a[idx] << " ";
	return;
}

int main()
{
	cin >> n;
	
	for (int i = 0; i < n; i++) cin >> a[i];

	fill(&pre[0], &pre[1003], -1);
	fill(&cnt[0], &cnt[1003], 1);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[j] < a[i] && cnt[i] < cnt[j] + 1)
			{
				cnt[i] = cnt[j] + 1;
				pre[i] = j;
				if (ret < cnt[i])
				{
					idx = i;
					ret = cnt[i];
				}
			}
		}
	}

	cout << ret << "\n";
	go(idx);

	return 0;
}