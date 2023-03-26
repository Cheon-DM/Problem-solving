/**
 * baekjoon - 1259
 * implementation, string
 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    string num;
    while (1)
    {
        cin >> num;

        if (num == "0")
            break;

        string rev = num;

        reverse(rev.begin(), rev.end());

        if (num == rev)
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }
    }

    return 0;
}