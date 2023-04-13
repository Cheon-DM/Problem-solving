/**
 * baekjoon - 2609
 * math, number theory, euclidean algorithm
 */

#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b)
{
    int tmp, r;
    if (a < b)
    {
        tmp = a;
        a = b;
        b = tmp;
    }

    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int lcd(int a, int b)
{
    int GCD = gcd(a, b);

    return (a / GCD) * b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    int a, b;
    cin >> a >> b;

    cout << gcd(a, b) << "\n";
    cout << lcd(a, b) << "\n";

    return 0;
}