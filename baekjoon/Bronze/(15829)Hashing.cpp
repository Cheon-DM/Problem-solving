/**
 * baekjoon - 15829
 * implementation, string, hashing
 */

#include <iostream>
#include <string>

#define MOD 1234567891
using namespace std;

int L;
string str;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // INPUT
    cin >> L;
    cin >> str;

    long long hash = 0;
    long long r = 1;
    for (int i = 0; i < L; i++)
    {
        char c = str[i];
        hash = (hash + (c - 'a' + 1) * r) % MOD;
        r = (r * 31) % MOD;
    }

    cout << hash << '\n';

    return 0;
}