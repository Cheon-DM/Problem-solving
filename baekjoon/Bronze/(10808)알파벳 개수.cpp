/**
 * baekjoon - 10808
 * implementation, string
 */

#include <iostream>
using namespace std;

int count[26] = {
    0,
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;

    for (int i = 0; i < str.size(); i++)
    {
        count[str[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (i == 0)
        {
            cout << count[i];
        }
        else
        {
            cout << " " << count[i];
        }
    }

    cout << '\n';

    return 0;
}