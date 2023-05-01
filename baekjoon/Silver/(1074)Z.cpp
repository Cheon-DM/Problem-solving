/**
 * baekjoon - 1074
 * Divide-and-conquer, recursion
 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, r, c;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // INPUT
    cin >> N >> r >> c;
    int l = pow(2, N) - 1;
    int d = pow(2, N);
    int h1 = 0, h2 = l;
    int w1 = 0, w2 = l;

    int th = 0;
    while (h1 < h2 || w1 < w2)
    {
        int mh = (h1 + h2) / 2;
        int mw = (w1 + w2) / 2;
        d /= 2;

        if (mh >= r && mw >= c)
        {
            h2 = mh;
            w2 = mw;
        }

        else if (mh >= r && mw < c)
        {
            th += (d * d);
            h2 = mh;
            w1 = mw + 1;
        }

        else if (mh < r && mw >= c)
        {
            th += 2 * (d * d);
            h1 = mh + 1;
            w2 = mw;
        }

        else
        {
            th += 3 * (d * d);
            h1 = mh + 1;
            w1 = mw + 1;
        }
    }

    cout << th << '\n';

    return 0;
}