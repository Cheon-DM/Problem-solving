/**
 * baekjoon - 1085
 *
 */

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int x, y, w, h;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> x >> y >> w >> h;

    int answer = 1000;

    answer = min(answer, abs(x - 0));
    answer = min(answer, abs(y - 0));
    answer = min(answer, abs(x - w));
    answer = min(answer, abs(y - h));

    cout << answer << endl;

    return 0;
}