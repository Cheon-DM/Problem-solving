/**
 * baekjoon - 1197
 * MST
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int V, E;
int parent[10001];

struct Edge
{
    int cost;
    int e1;
    int e2;
};

struct cmp
{
    bool operator()(Edge a, Edge b)
    {
        return a.cost > b.cost;
    }
};

int find(int x)
{
    if (x == parent[x])
        return x;

    return parent[x] = find(parent[x]);
}

void Union(int a, int b)
{
    a = find(a);
    b = find(b);

    parent[a] = b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // INPUT
    cin >> V >> E;

    int a, b, c;
    priority_queue<Edge, vector<Edge>, cmp> pq;
    for (int i = 0; i < E; i++)
    {
        cin >> a >> b >> c;
        pq.push({c, a, b});
    }

    // init
    for (int i = 1; i <= V; i++)
    {
        parent[i] = i;
    }

    int w = 0;
    while (!pq.empty())
    {
        int cost = pq.top().cost;
        int e1 = pq.top().e1;
        int e2 = pq.top().e2;
        pq.pop();

        if (find(e1) != find(e2))
        {
            Union(e1, e2);
            w += cost;
        }
    }

    cout << w << endl;

    return 0;
}