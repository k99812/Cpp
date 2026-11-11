#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class Solution 
{
    typedef long long ll;

    struct Server
    {
        int priority, idx;

        bool operator<(const Server& other) const
        {
            if (priority == other.priority) return idx > other.idx;
            return priority > other.priority;
        }
    };

    struct Job
    {
        int priority, idx;
        ll time;

        bool operator<(const Job& other) const
        {
            return time > other.time;
        }
    };

public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) 
    {
        int n = servers.size(), m = tasks.size();

        priority_queue<Server> server_pq;
        priority_queue<Job> job_pq;

        for (int i = 0; i < n; i++)
        {
            server_pq.push({ servers[i], i });
        }

        ll time = 0;
        vector<int> ret(m, -1);

        for (int i = 0; i < m; i++)
        {
            time = max(time, (ll)i);

            if (server_pq.empty())
            {
                time = job_pq.top().time;
            }

            while (job_pq.size() && job_pq.top().time <= time)
            {
                server_pq.push({ job_pq.top().priority, job_pq.top().idx });
                job_pq.pop();
            }

            const auto [pri, idx] = server_pq.top();
            server_pq.pop();

            ret[i] = idx;
            job_pq.push({ pri, idx, time + tasks[i] });
        }

        return ret;
    }
};

int main()
{

	return 0;
}