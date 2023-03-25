/**
 * baekjoon - 1725
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1000000001
using namespace std;

struct Node
{
    int index;
    int height;
};

int N, S;
int ans;
vector<int> inputs;
vector<Node> tree;

void initTree()
{
    tree.assign(2 * S, {0, INF});

    // leaf node
    for (int i = 1; i <= N; i++)
    {
        tree[i + S - 1] = {i, inputs[i]};
    }

    // inner node
    for (int i = S - 1; i >= 1; i--)
    {
        Node left = tree[i * 2];
        Node right = tree[i * 2 + 1];

        if (left.height <= right.height)
        {
            tree[i] = left;
        }
        else
        {
            tree[i] = right;
        }
    }
}

Node query(int left, int right, int node, int qLeft, int qRight)
{
    // 연관 없음
    if (qRight < left || right < qLeft)
        return {0, INF};

    // 판단 가능
    if (qLeft <= left && right <= qRight)
        return tree[node];

    // 판단 불가
    int mid = (left + right) / 2;
    Node l = query(left, mid, node * 2, qLeft, qRight);
    Node r = query(mid + 1, right, node * 2 + 1, qLeft, qRight);

    if (l.height <= r.height)
        return l;
    else
        return r;
}

void getWidth(int start, int end)
{
    // start~end까지 query 실행
    Node cur = query(1, S, 1, start, end);
    int res = (end - start + 1) * cur.height;
    ans = max(ans, res);

    // 다음 단계 진행 확인
    if (start == end)
    {
        return;
    }
    if (start <= cur.index - 1)
    {
        getWidth(start, cur.index - 1);
    }
    if (end >= cur.index + 1)
    {
        getWidth(cur.index + 1, end);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> N;
    inputs.assign(N + 1, 0);

    for (int i = 1; i <= N; i++)
    {
        cin >> inputs[i];
    }

    // start leaf node num = S
    S = 1;
    while (S < N)
    {
        S *= 2;
    }

    initTree();

    ans = 0;
    getWidth(1, N);

    cout << ans << "\n";

    return 0;
}