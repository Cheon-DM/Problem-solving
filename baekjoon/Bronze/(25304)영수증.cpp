/**
 * baekjoon - 25304
 * math, implementation
 */

#include <iostream>
#include <vector>
using namespace std;

int X, N;
int a, b;
int total = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // INPUT
    cin >> X;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;
        total += (a * b);
    }

    if (total == X)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }

    return 0;
}