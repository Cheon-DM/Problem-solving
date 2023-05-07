/**
 * baekjoon - 11724
 * union-find
 */

#include <iostream>
#include <vector>
using namespace std;

int N, K;
int u, v;
int parent[1001];

int Find(int x)
{
    if (x == parent[x])
    {
        return x;
    }

    return x = Find(parent[x]);
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);

    parent[a] = b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // INIT
    for (int i = 0; i < 1001; i++)
    {
        parent[i] = i;
    }

    // INPUT
    cin >> N >> K;
    for (int i = 0; i < K; i++)
    {
        cin >> u >> v;
        Union(u, v);
    }

    int cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        if (parent[i] == i)
        {
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}