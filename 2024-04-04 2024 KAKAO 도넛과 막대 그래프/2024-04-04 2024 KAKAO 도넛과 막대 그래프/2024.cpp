#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>

#define MAX_NUM 1000000 + 4

using namespace std;

struct Result
{
    int RootNode,
        Pie,
        Bar,
        Eight;
};

int In[MAX_NUM], Out[MAX_NUM], root;
vector<int> grap[MAX_NUM];
queue<int> q;
Result ret;

void bfs(int start)
{
    q.push(start);

    bool isVisit = false;
    while (q.size())
    {
        int here = q.front();
        q.pop();

        if (isVisit && here == start)
        {
            ret.Pie++;
            return;
        }

        if (grap[here].size() >= 2)
        {
            ret.Eight++;
            return;
        }

        for (int next : grap[here])
        {
            isVisit = true;
            q.push(next);
        }
    }

    ret.Bar++;
    return;
}

vector<int> solution(vector<vector<int>> edges) 
{
    int mNum = -1;
    for (vector<int> v : edges)
    {
        grap[v[0]].push_back(v[1]);
        Out[v[0]]++;
        In[v[1]]++;
        mNum = max(mNum, max(v[0], v[1]));
    }

    for (int i = 1; i <= mNum; i++)
    {
        if (In[i] == 0 && Out[i] >= 2)
        {
            ret.RootNode = i;
        }
    }

    for (int start : grap[ret.RootNode])
    {
        bfs(start);
    }

    vector<int> answer;
    answer.push_back(ret.RootNode), answer.push_back(ret.Pie), 
        answer.push_back(ret.Bar), answer.push_back(ret.Eight);

    return answer;
}

int main()
{
    vector<vector<int>> input;

    vector<int> temp;

    temp.push_back(2), temp.push_back(3);
    input.push_back(temp);
    temp.clear();

    temp.push_back(4), temp.push_back(3);
    input.push_back(temp);
    temp.clear();

    temp.push_back(1), temp.push_back(1);
    input.push_back(temp);
    temp.clear();

    temp.push_back(2), temp.push_back(1);
    input.push_back(temp);
    temp.clear();

    for (int a : solution(input))
    {
        cout << a << " ";
    }

	return 0;
}