/**
 * baekjoon - 2630
 * recursion
 */

#include <iostream>
#include <vector>
using namespace std;

int N;
int paper[128][128];
int white = 0;
int blue = 0;

void sol(int h1, int h2, int w1, int w2)
{
    if (h1 > h2 || w1 > w2)
        return;

    int f = 0;
    bool flag = false;
    int mh = (h1 + h2) / 2;
    int mw = (w1 + w2) / 2;

    for (int i = h1; i <= h2; i++)
    {
        for (int j = w1; j <= w2; j++)
        {
            if (i == h1 && j == w1)
            {
                f = paper[i][j];
            }

            else
            {
                if (f != paper[i][j])
                {
                    // 다음 단계 이동
                    flag = true;
                    break;
                }
            }
        }
    }

    if (flag)
    {
        sol(h1, mh, w1, mw);
        sol(h1, mh, mw + 1, w2);
        sol(mh + 1, h2, w1, mw);
        sol(mh + 1, h2, mw + 1, w2);
    }

    else
    {
        if (f == 0)
        {
            white++;
        }

        else
        {
            blue++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // INPUT
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> paper[i][j];
        }
    }

    sol(0, N - 1, 0, N - 1);
    cout << white << '\n';
    cout << blue << '\n';

    return 0;
}