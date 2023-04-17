/**
 * baekjoon - 1043
 * disjoint set
 */

#include <iostream>
#include <vector>
using namespace std;

int N, M, K;
int parent[51];
vector<int> know;
vector<vector<int>> partyList(50);

int Find(int x)
{
    if (parent[x] == x)
    {
        return x;
    }

    return Find(parent[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);

    if (x != y)
    {
        parent[x] = y;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> N >> M;
    cin >> K;
    int n;
    for (int i = 0; i < K; i++)
    {
        cin >> n;
        know.push_back(n);
    }

    // init
    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < M; i++)
    {
        int p;
        cin >> p;
        int num, prev;
        for (int j = 0; j < p; j++)
        {
            if (j >= 1)
            {
                prev = num;
                cin >> num;
                Union(prev, num);
            }
            else
            {
                cin >> num;
            }
            partyList[i].push_back(num);
        }
    }

    int ans = M;
    for (int i = 0; i < M; i++) // party 개수
    {
        bool flag = false;
        for (int j = 0; j < partyList[i].size(); j++) // party 참가 인원 수
        {
            if (flag)
                break;
            for (int k = 0; k < know.size(); k++)
            { // know의 부모와 party 참가 인원의 부모가 같은지 확인
                if (Find(partyList[i][j]) == Find(know[k]))
                {
                    flag = true;
                    break;
                }
            }
        }
        if (flag)
            ans--;
    }

    cout << ans << '\n';

    return 0;
}