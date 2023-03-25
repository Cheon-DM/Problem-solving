/**
 * baekjoon - KCM Travel
 * dp, graph, dijkstra
 */

#include <iostream>
#include <vector>
#include <queue>

#define INF 0xFFFFFF

using namespace std;

struct Ticket
{
    int end;
    int cost;
    int time;
};

struct compare
{
    bool operator()(const Ticket &t1, const Ticket &t2)
    {
        return t1.time > t2.time;
    }
};

int T, N, M, K;
vector<vector<Ticket>> lines;
int dp[101][10001]; // N공항에서 M비용으로 걸린 최소 시간

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    for (int t = 0; t < T; t++)
    {
        cin >> N >> M >> K;

        // init
        lines.clear();
        for (int i = 0; i < N + 1; i++)
        {
            vector<Ticket> tmp;
            lines.push_back(tmp);
        }
        for (int i = 0; i < N + 1; i++)
        {
            for (int j = 0; j < M + 1; j++)
            {
                dp[i][j] = INF;
            }
        }

        for (int i = 0; i < K; i++)
        {
            int u, v, c, d;
            cin >> u >> v >> c >> d;
            lines[u].push_back({v, c, d});
        }

        priority_queue<Ticket, vector<Ticket>, compare> pq;
        pq.push({1, 0, 0});

        dp[1][0] = 0;

        while (!pq.empty())
        {
            // 현재 티켓 정보
            int cur = pq.top().end;
            int time = pq.top().time;
            int cost = pq.top().cost;
            pq.pop();

            if (dp[cur][cost] < time)
                continue;

            for (int i = 0; i < lines[cur].size(); i++)
            {
                // 현재 공항에서 다음 공항으로 이동할 수 있는 티켓 = next
                int next = lines[cur][i].end;
                int nTime = time + lines[cur][i].time;
                int nCost = cost + lines[cur][i].cost;

                // 현재 공항까지 사용한 비용에 다음 공항까지 이동할 수 있는 비용이 M이하인 경우만 가능
                if (nCost <= M && nTime < dp[next][nCost])
                {
                    dp[next][nCost] = nTime;
                    pq.push({next, nCost, nTime});
                }
            }
        }

        int ans = INF;
        for (int i = 1; i <= M; i++)
        {
            if (ans > dp[N][i])
            {
                ans = dp[N][i];
            }
        }

        if (ans == INF)
        {
            cout << "Poor KCM\n";
        }
        else
        {
            cout << ans << "\n";
        }
    }

    return 0;
}