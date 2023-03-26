/**
 * baekjoon - 1436
 * brute force
 */

#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int N;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> N;

    bool flag = false;
    int pattern = 666;
    string target;
    int cnt = 0;

    while (1)
    {
        target = to_string(pattern);
        for (int i = 0; i < target.size() - 2; i++)
        {
            if (target[i] == '6' && target[i + 1] == '6' && target[i + 2] == '6')
            {
                cnt++;

                if (cnt == N)
                {
                    flag = true;
                }
                break;
            }
        }

        if (flag)
            break;

        pattern++;
    }

    cout << pattern;
}