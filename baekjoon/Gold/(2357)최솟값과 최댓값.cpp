/**
 * baekjoon - 2357
 * segment tree
 */

#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000001
using namespace std;

struct Node
{
    int Min;
    int Max;
};

int N, M, S;
vector<int> inputs;
vector<Node> tree;

void initTree()
{
    tree.assign(2 * S, {INF, 0});

    // leaf node
    for (int i = 1; i <= N; i++)
    {
        tree[S + i - 1] = {inputs[i], inputs[i]};
    }

    // inner node
    for (int i = S - 1; i >= 1; i--)
    {
        Node leftChild = tree[i * 2];
        Node rightChild = tree[i * 2 + 1];

        tree[i].Min = min(leftChild.Min, rightChild.Min);
        tree[i].Max = max(leftChild.Max, rightChild.Max);
    }
}

Node query(int left, int right, int node, int qLeft, int qRight)
{
    // 연관 없음
    if (qRight < left || right < qLeft)
        return {INF, 0};

    // 판단 가능
    if (qLeft <= left && right <= qRight)
        return tree[node];

    // 판단 불가
    int mid = (left + right) / 2;
    Node leftChild = query(left, mid, node * 2, qLeft, qRight);
    Node rightChild = query(mid + 1, right, node * 2 + 1, qLeft, qRight);

    return {min(leftChild.Min, rightChild.Min), max(leftChild.Max, rightChild.Max)};
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

        Node ans = query(1, S, 1, a, b);
        cout << ans.Min << " " << ans.Max << "\n";
    }

    return 0;
}