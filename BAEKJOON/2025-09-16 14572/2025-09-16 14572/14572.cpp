#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

struct Info
{
	int skill;
	vector<int> algo;
};

int n, k, d;
vector<Info> student;

int main()
{
	cin >> n >> k >> d;

	student = vector<Info>(n);

	for (int i = 0; i < n; i++)
	{
		int m, s;
		cin >> m >> s;

		student[i].skill = s;
		student[i].algo.resize(m);

		for (int j = 0; j < m; j++)
		{
			cin >> student[i].algo[j];
		}
	}

	sort(student.begin(), student.end(),
		[](const Info& a, const Info& b)
	{
		return a.skill < b.skill;
	});

	int left = 0;
	ll ret = 0;
	vector<int> know_algo_cnt(k + 1);

	for (int right = 0; right < n; right++)
	{
		for (const int& algo_num : student[right].algo)
		{
			know_algo_cnt[algo_num]++;
		}

		while (student[right].skill - student[left].skill > d)
		{
			for (const int& algo_num : student[left].algo)
			{
				know_algo_cnt[algo_num]--;
			}

			left++;
		}

		int group_size = right - left + 1, total = 0, all_know = 0;

		for (int i = 1; i <= k; i++)
		{
			if (know_algo_cnt[i]) total++;
			if (know_algo_cnt[i] == group_size) all_know++;
		}

		ll effi = 1LL * (total - all_know) * group_size;
		ret = max(ret, effi);
	}
		
	cout << ret << "\n";

	return 0;
}