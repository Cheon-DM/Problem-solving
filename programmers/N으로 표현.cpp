/**
 * programmers - N으로 표현
 * dp
 */

#include <vector>
#include <unordered_set>

using namespace std;

int getNumber(int n, int idx)
{
    // N 나열 숫자
    int res = n;

    for (int i = 1; i < idx; i++)
    {
        res = res * 10 + n;
    }

    return res;
}

int solution(int N, int number)
{
    int answer = 0;

    // N과 number이 같다면 한 개로 충분
    if (N == number)
        return 1;

    vector<unordered_set<int>> dp(9);

    dp[1].insert(N);

    for (int i = 2; i <= 8; i++)
    {
        dp[i].insert(getNumber(N, i));

        for (int m = 0; m < i; m++)
        {
            for (int n = 0; n < i; n++)
            {

                if (m + n != i)
                    continue;

                for (auto a : dp[m])
                {
                    for (auto b : dp[n])
                    {
                        dp[i].insert(a + b);
                        if (a - b > 0)
                        {
                            dp[i].insert(a - b);
                        }
                        dp[i].insert(a * b);
                        if (a / b > 0)
                        {
                            dp[i].insert(a / b);
                        }
                    }
                }
            }
        }

        if (dp[i].find(number) != dp[i].end())
        {
            return i;
        }
    }

    return -1;
}