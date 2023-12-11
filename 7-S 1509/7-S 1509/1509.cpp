#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string s;
const int INF = 1e9;
int dp[2504][2504], dp2[2504];

int go(int here)
{
    if (here == s.size()) return 0;

    int& ret = dp2[here];
    if (ret != INF) return ret;

    for (int i = 1; i <= s.size() - here; i++)
    {
        if (dp[here][i]) ret = min(ret, go(here + i) + 1);
    }
    cout << here << " : " << ret << "\n";
    return ret;
}

int main() {
    cin >> s; 

    for (int i = 0; i < s.size(); i++) dp[i][1] = 1;

    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            dp[i][2] = 1;
        }
    }

    for (int size = 3; size <= s.size(); size++)
    {
        for (int j = 0; j <= s.size() - size; j++)
        {
            if (s[j] == s[j + size - 1] && dp[j + 1][size - 2]) dp[j][size] = 1;
        }
    }

    fill(&dp2[0], &dp2[2504], INF);
    cout << go(0) << "\n";

    return 0;
} 