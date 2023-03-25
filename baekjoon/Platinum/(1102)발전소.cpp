/**
 * baekjoon - 1102
 * dp, bitmask
 */

#include <iostream>
#include <algorithm>

#define INF 10000000
using namespace std;

int N, P;
int MAP[17][17];
int cost[1 << 16]; // cost[100000110] : 2, 3, 9번째 발전소가 켜져있을 때 최소 비용
string S;

int cal(int bit)
{
    int cnt = 0;
    while (bit != 0)
    {
        cnt += (bit & 1);
        bit = bit >> 1;
    }
    return cnt;
}

int dfs(int bit)
{
    // P개 이상의 발전소 ON
    if (cal(bit) >= P)
        return 0;

    // cost[bit]가 이미 구해진 경우 해당 값 반환
    if (cost[bit] != -1)
        return cost[bit];

    cost[bit] = INF;
    for (int i = 0; i < N; i++)
    {
        // ON인 발전소 찾기
        if ((bit & (1 << i)) == 0)
            continue;

        for (int j = 0; j < N; j++)
        {
            // OFF인 발전소 찾기
            if ((bit & (1 << j)) == 0)
            {
                int nextBit = bit | (1 << j);
                cost[bit] = min(cost[bit], MAP[i][j] + dfs(nextBit));
            }
        }
    }

    return cost[bit];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> MAP[i][j];
        }
    }
    cin >> S;
    cin >> P;

    // 비트마스크 설정
    int BitState = 0;
    for (int i = 0; i < S.length(); i++)
    {
        if (S[i] == 'Y')
        {
            BitState = BitState | (1 << i);
        }
    }

    fill_n(&cost[0], 1 << 16, -1);

    int ans = dfs(BitState);
    if (ans == INF)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << ans << "\n";
    }

    return 0;
}