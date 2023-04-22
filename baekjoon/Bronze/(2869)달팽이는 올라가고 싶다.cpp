/**
 * baekjoon - 2869
 * math
 */

#include <iostream>
#include <cmath>
using namespace std;

int A, B, V;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> A >> B >> V;

    int day = 0;

    // 1 day
    V -= A;
    day++;

    // rest day
    int diff = A - B;
    double q = (double)V / (double)diff;
    day += ceil(q);

    cout << day << '\n';

    return 0;
}