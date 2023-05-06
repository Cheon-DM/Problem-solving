/**
 * baekjoon - 27866
 * string
 */

#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // INPUT
    string str;
    cin >> str;

    int i;
    cin >> i;

    cout << str[i - 1] << endl;

    return 0;
}