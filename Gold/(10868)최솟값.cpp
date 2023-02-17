/**
 * baekjoon - 10868
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000001
using namespace std;

int N, M, S;
vector<int> inputs;
vector<int> tree;

void initTree()
{
    tree.assign(2 * S, INF);

    // leaf node
    for (int i = 1; i <= N; i++)
    {
        tree[S + i - 1] = inputs[i];
    }

    // inner node
    for (int i = S - 1; i >= 1; i--)
    {
        int leftChild = tree[i * 2];
        int rightChild = tree[i * 2 + 1];

        tree[i] = min(leftChild, rightChild);
    }
}

int query(int left, int right, int node, int qLeft, int qRight)
{
    // 연관 없음
    if (qRight < left || right < qLeft)
        return INF;

    // 판단 가능
    if (qLeft <= left && right <= qRight)
        return tree[node];

    // 판단 불가
    int mid = (left + right) / 2;
    int leftChild = query(left, mid, node * 2, qLeft, qRight);
    int rightChild = query(mid + 1, right, node * 2 + 1, qLeft, qRight);

    return min(leftChild, rightChild);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> N >> M;

    inputs.assign(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        cin >> inputs[i];
    }

    // tree leaf node start = S
    S = 1;
    while (S < N)
    {
        S *= 2;
    }

    initTree();

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;

        int ans = query(1, S, 1, a, b);
        cout << ans << "\n";
    }

    return 0;
}