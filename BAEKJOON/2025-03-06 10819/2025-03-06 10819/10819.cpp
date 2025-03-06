#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, ret = INT32_MIN;

int sum(const vector<int>& temp)
{
    int sum = 0;
    for (int i = 0; i < temp.size() - 1; i++)
    {
        sum += abs(temp[i] - temp[i + 1]);
    }
    return sum;
}

void go(int idx, const vector<int>& v, vector<int>& temp, vector<int>& visited)
{
    if (idx == n)
    {
        ret = max(ret, sum(temp));
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (visited[i]) continue;

        visited[i] = 1;
        temp[idx] = v[i];
        go(idx + 1, v, temp, visited);
        visited[i] = 0;
    }
}

int main()
{
    cin >> n;

    vector<int> v(n), temp(n), visited(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    go(0, v, temp, visited);

    cout << ret << "\n";

    return 0;
}