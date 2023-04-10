/**
 * programmers - 합승 택시 요금
 * dijkstra
 */

#include <string>
#include <vector>
#include <queue>

#define INF 20000000

using namespace std;

struct Node
{
    int node;
    int cost;
};

struct cmp
{
    bool operator()(Node a, Node b)
    {
        return a.cost > b.cost;
    }
};

vector<Node> links[201];
int distS[201];
int distA[201];
int distB[201];

void dijkstra(int start, int dist[])
{
    priority_queue<Node, vector<Node>, cmp> pq;
    pq.push({start, 0});
    dist[start] = 0;

    while (!pq.empty())
    {
        int node = pq.top().node;
        int cost = pq.top().cost;
        pq.pop();

        for (int i = 0; i < links[node].size(); i++)
        {
            int next = links[node][i].node;
            int nCost = cost + links[node][i].cost;

            if (nCost < dist[next])
            {
                dist[next] = nCost;
                pq.push({next, nCost});
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{
    int answer = INF;

    for (int i = 0; i < 201; i++)
    {
        distS[i] = INF;
        distA[i] = INF;
        distB[i] = INF;
    }

    for (int i = 0; i < fares.size(); i++)
    {
        int start = fares[i][0];
        int end = fares[i][1];
        int cost = fares[i][2];

        links[start].push_back({end, cost});
        links[end].push_back({start, cost});
    }

    dijkstra(s, distS);
    dijkstra(a, distA);
    dijkstra(b, distB);

    for (int i = 1; i <= n; i++)
    {
        int dist = distS[i] + distA[i] + distB[i];
        if (answer > dist)
        {
            answer = dist;
        }
    }

    return answer;
}