/**
 * baekjoon - 2798
 * brute force
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int card[100];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> card[i];
    }

    sort(&card[0], &card[N]);

    int answer = 0;
    for (int i = 0; i < N - 2; i++)
    {
        for (int j = i + 1; j < N - 1; j++)
        {
            for (int k = j + 1; k < N; k++)
            {
                int total = card[i] + card[j] + card[k];
                if (total <= M)
                {
                    answer = max(answer, total);
                }
            }
        }
    }

    cout << answer << "\n";

    return 0;
}