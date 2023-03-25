/**
 * baekjoon - 3653
 * segment tree
 */

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1 << 19
using namespace std;

int S = MAX;
int T, N, M;
int loc[MAX];
int tree[2 * MAX];
vector<int> ans;

void init()
{
    // reset
    fill_n(&loc[0], MAX, 0);
    fill_n(&tree[0], 2 * MAX, 0);

    // location
    for (int i = 1; i <= N; i++)
    {
        loc[i] = N - i + 1;
    }

    // leaf node
    for (int i = 0; i < N; i++)
    {
        tree[i + S] = 1;
    }

    // inner node
    for (int i = S - 1; i > 0; i--)
    {
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
}

int query(int left, int right, int node, int qLeft, int qRight)
{
    // 연관 없음
    if (right < qLeft || qRight < left)
        return 0;

    // 판단 가능
    if (qLeft <= left && right <= qRight)
        return tree[node];

    // 판단 불가
    int mid = (left + right) / 2;
    int l = query(left, mid, node * 2, qLeft, qRight);
    int r = query(mid + 1, right, node * 2 + 1, qLeft, qRight);
    return l + r;
}

void update(int left, int right, int node, int target, int diff)
{
    // 연관 없음
    if (target < left || right < target)
        return;

    // 연관 있음
    tree[node] += diff;
    if (left != right)
    {
        int mid = (left + right) / 2;
        update(left, mid, node * 2, target, diff);
        update(mid + 1, right, node * 2 + 1, target, diff);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // testcase input
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        // input
        cin >> N >> M;

        // init
        init();
        ans.clear();

        for (int i = 1; i <= M; i++)
        {
            int fIdx;
            cin >> fIdx;

            ans.push_back(query(1, MAX, 1, loc[fIdx] + 1, N + i - 1));
            update(1, MAX, 1, loc[fIdx], -1);
            update(1, MAX, 1, N + i, 1);
            loc[fIdx] = N + i;
        }

        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}