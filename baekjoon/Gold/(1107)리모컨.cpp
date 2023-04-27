/**
 * baekjoon - 1107
 * dfs, brute force
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

int N, M;
int Size;
int cnt;
bool isBroken[10] = {
    false,
};

void dfs(int level, int num)
{
    if (level >= Size - 1 && level <= Size + 1)
    {
        int count = 0;
        string str = to_string(num);
        count += str.size();
        count += abs(N - num);
        cnt = min(cnt, count);

        if (level == Size + 1)
        {
            return;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        if (!isBroken[i])
        {
            int tmp = num;
            tmp *= 10;
            tmp += i;
            dfs(level + 1, tmp);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // INPUT
    cin >> N >> M;
    int n;
    for (int i = 0; i < M; i++)
    {
        cin >> n;
        isBroken[n] = true;
    }

    // INIT
    int channel = 100;
    cnt = abs(N - 100);

    Size = to_string(N).size();

    // 시작 채널 = 100
    if (N == 100)
    {
        cout << 0 << '\n';
        return 0;
    }

    for (int i = 0; i < 10; i++)
    {
        if (!isBroken[i])
        {
            dfs(1, i);
        }
    }

    cout << cnt << '\n';

    return 0;
}