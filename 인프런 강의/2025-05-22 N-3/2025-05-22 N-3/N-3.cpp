#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

struct cmp
{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const
    {
        if (a.first == b.first) return a.second > b.second; // 인덱스 작은 쪽 우선
        return a.first < b.first; // 기여도 큰 쪽 우선
    }
};

long long find_vip_score_sum(vector<int>& score, int guilder_count, int k)
{
    int n = score.size();
    long long total = 0;

    // 최대 힙: 값이 같을 경우 인덱스가 작은 것이 우선
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> front_q, back_q;
    set<int> removed;

    int left = 0, right = n - 1;

    // 초기 k개씩 큐에 채우기
    for (int i = 0; i < k && i < n; ++i)
    {
        front_q.emplace(score[i], i);
    }
    for (int i = n - 1; i >= max(n - k, 0); --i)
    {
        back_q.emplace(score[i], i);
    }

    for (int count = 0; count < guilder_count; ++count)
    {
        pair<int, int> front_top = front_q.empty() ? make_pair(-1, -1) : front_q.top();
        pair<int, int> back_top = back_q.empty() ? make_pair(-1, -1) : back_q.top();

        // 최대값 선택
        pair<int, int> selected;
        if (front_top.first > back_top.first)
        {
            selected = front_top;
            front_q.pop();
        }
        else if (back_top.first > front_top.first)
        {
            selected = back_top;
            back_q.pop();
        }
        else
        { // 값 같으면 인덱스 작은 쪽
            if (front_top.second <= back_top.second)
            {
                selected = front_top;
                front_q.pop();
            }
            else
            {
                selected = back_top;
                back_q.pop();
            }
        }

        total += selected.first;
        removed.insert(selected.second);

        // 유효한 front 최대값 꺼내기
        while (!front_q.empty() && removed.count(front_q.top().second)) front_q.pop();
        while (!back_q.empty() && removed.count(back_q.top().second)) back_q.pop();

        // 앞쪽 윈도우 보정
        if (front_q.size() < k && left < n)
        {
            ++left;
            if (left + k - 1 < n)
            {
                front_q.emplace(score[left + k - 1], left + k - 1);
            }
        }

        // 뒤쪽 윈도우 보정
        if (back_q.size() < k && right >= 0)
        {
            --right;
            if (right - k + 1 >= 0)
            {
                front_q.emplace(score[right - k + 1], right - k + 1);
            }
        }
    }

    return total;
}

int main() 
{
    vector<int> score = { 8, 21, 8, 15, 5, 30, 21 };
    int guilder_count = 2;
    int k = 3;

    cout << find_vip_score_sum(score, guilder_count, k) << endl; // 출력: 51

    return 0;
}