/**
 * baekjoon - 2164
 * queue
 */

#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

int N;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> N;

    queue<int> q;
    for (int i = 1; i <= N; i++)
    {
        q.push(i);
    }

    while (1)
    {
        if (q.size() == 1)
        {
            break;
        }

        q.pop();

        int front = q.front();
        q.pop();
        q.push(front);
    }

    int answer = q.front();

    cout << answer << "\n";

    return 0;
}