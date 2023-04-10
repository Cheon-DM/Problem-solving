/**
 * baekjoon - 1929
 * Sieve of Eratosthenes
 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, M;
bool isPrime[1000001] = {
    false,
};

void prime(int num)
{
    isPrime[0] = true;
    isPrime[1] = true;

    for (int i = 2; i <= sqrt(num); i++)
    {
        if (!isPrime[i])
        {
            for (int j = i * 2; j <= num; j += i)
            {
                isPrime[j] = true;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> M >> N;

    prime(N);

    for (int i = M; i <= N; i++)
    {
        if (!isPrime[i])
        {
            cout << i << "\n";
        }
    }

    return 0;
}