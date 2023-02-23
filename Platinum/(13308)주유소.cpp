/**
 * baekjoon - 13308
 * dp, graph, dijkstra
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX_N 2501
#define INF 1e15
using namespace std;

struct City
{
    int city;
    int minGas;
    long long cost;
};

struct compare
{
    bool operator()(City c1, City c2)
    {
        return c1.cost > c2.cost;
    }
};

int N, M;
int gas[MAX_N];
long long dp[MAX_N][MAX_N];
vector<vector<City>> city(MAX_N);

void dijkstra()
{
    long long ans;
    priority_queue<City, vector<City>, compare> pq;
    pq.push({1, gas[1], 0});

    while (!pq.empty())
    {
        int cur_City = pq.top().city;
        int curGas = pq.top().minGas;
        long long cost = pq.top().cost;
        pq.pop();

        // 이미 해당 도시에서 해당 최소 기름값에 대한 dp값 존재
        if (dp[cur_City][curGas] < cost)
            continue;

        // 도착지
        if (cur_City == N)
        {
            ans = cost;
            break;
        }

        for (int i = 0; i < city[cur_City].size(); i++)
        {
            int next_City = city[cur_City][i].city;
            long long nCost = cost + city[cur_City][i].cost * curGas;
            int nGas = min(curGas, gas[next_City]);

            if (dp[next_City][curGas] > nCost)
            {
                dp[next_City][curGas] = nCost;
                pq.push({next_City, nGas, nCost});
            }
        }
    }

    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        cin >> gas[i];
    }

    for (int i = 1; i <= M; i++)
    {
        int s, e, c;
        cin >> s >> e >> c;
        city[s].push_back({e, gas[s], c});
        city[e].push_back({s, gas[e], c});
    }

    // init
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j < MAX_N; j++)
        {
            dp[i][j] = INF;
        }
    }
    dijkstra();

    return 0;
}