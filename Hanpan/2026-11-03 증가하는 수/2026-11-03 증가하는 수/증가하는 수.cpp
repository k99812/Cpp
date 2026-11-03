#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

vector<string> v;

void go(int idx, string s)
{
    for (int i = idx; idx <= 9; idx++)
    {
        string temp = s;
        temp += idx + '0';
        v.push_back(temp);
        go(idx + 1, temp);
    }
}

string solution(int k) 
{
    go(0, "");

    sort(v.begin(), v.end(),
        [](const string& a, const string& b)
    {
        if (a.size() == b.size()) return a < b;
        return a.size() < b.size();
    });

    if (k > v.size()) return "-1";

    return v[k - 1];
}

int main()
{
    cout << solution(1023);

    return 0;
}