/**
 * baekjoon - 10773
 * implementation, stack
 */

#include <iostream>
#include <stack>
using namespace std;

int K;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // INPUT
    cin >> K;

    int num;
    stack<int> s;
    for (int i = 0; i < K; i++)
    {
        cin >> num;

        if (num == 0)
        {
            s.pop();
        }

        else
        {
            s.push(num);
        }
    }

    int total = 0;
    while (!s.empty())
    {
        total += s.top();
        s.pop();
    }

    cout << total << '\n';

    return 0;
}