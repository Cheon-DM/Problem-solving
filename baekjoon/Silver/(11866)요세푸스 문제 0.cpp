/**
 * baekjoon - 11866
 * queue
 */

#include <iostream>
#include <queue>
using namespace std;

int N, K;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> N >> K;

    queue<int> q;
    for (int i = 1; i <= N; i++)
    {
        q.push(i);
    }

    cout << "<";
    while (!q.empty())
    {
        for (int i = 0; i < K - 1; i++)
        {
            int front = q.front();
            q.pop();
            q.push(front);
        }

        cout << q.front();
        q.pop();
        if (!q.empty())
        {
            cout << ", ";
        }
    }
    cout << ">\n";

    return 0;
}