#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class Solution 
{
    struct Buy
    {
        int price, amount;

        bool operator<(const Buy& other) const
        {
            return price < other.price;
        }
    };

    struct Sell
    {
        int price, amount;

        bool operator<(const Sell& other) const
        {
            return price > other.price;
        }
    };

    const int BUY = 0;
    const int SELL = 1;
    const int MOD = 1e9 + 7;

public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) 
    {
        int n = orders.size();
        priority_queue<Buy> buy_pq;
        priority_queue<Sell> sell_pq;

        for (int i = 0; i < n; i++)
        {
            int price = orders[i][0], amount = orders[i][1], type = orders[i][2];

            if (type == BUY)
            {
                while (amount > 0 && sell_pq.size() && sell_pq.top().price <= price)
                {
                    auto [p, a] = sell_pq.top();
                    sell_pq.pop();

                    int min_a = min(a, amount);

                    a -= min_a;
                    amount -= min_a;

                    if (a > 0)
                    {
                        sell_pq.push({ p, a });
                    }
                }

                if (amount > 0)
                {
                    buy_pq.push({ price, amount });
                }
            }
            else
            {
                while (amount > 0 && buy_pq.size() && buy_pq.top().price >= price)
                {
                    auto [p, a] = buy_pq.top();
                    buy_pq.pop();

                    int min_a = min(a, amount);

                    a -= min_a;
                    amount -= min_a;

                    if (a > 0)
                    {
                        buy_pq.push({ p, a });
                    }
                }

                if (amount > 0)
                {
                    sell_pq.push({ price, amount });
                }
            }
        }

        int ret = 0;
        while (buy_pq.size() || sell_pq.size())
        {
            if (buy_pq.size())
            {
                ret = (ret + buy_pq.top().amount) % MOD;
                buy_pq.pop();
            }

            if (sell_pq.size())
            {
                ret = (ret + sell_pq.top().amount) % MOD;
                sell_pq.pop();
            }
        }

        return ret;
    }
};

int main()
{

	return 0;
}