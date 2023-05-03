/**
 * baekjoon - 1927
 * minHeap, priority queue
 */

#include <iostream>
#include <queue>
using namespace std;

int N;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // INPUT
    cin >> N;
    long long num;
    priority_queue<long long, vector<long long>, greater<>> pq;
    while (N--)
    {
        cin >> num;

        if (num == 0)
        {
            if (pq.empty())
            {
                cout << 0 << '\n';
            }

            else
            {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }

        else
        {
            pq.push(num);
        }
    }

    return 0;
}