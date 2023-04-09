/**
 * baekjoon - 1978
 * prime
 */

#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> v;
bool isPrime[1001] = {
    false,
}; // false = 소수, true = 소수 아님

void prime()
{
    isPrime[0] = true;
    isPrime[1] = true;

    for (int i = 2; i <= 1000; i++)
    {
        if (!isPrime[i])
        {
            for (int j = i * 2; j <= 1000; j += i)
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
    cin >> N;
    int n;
    for (int i = 0; i < N; i++)
    {
        cin >> n;
        v.push_back(n);
    }

    prime();
    int answer = 0;
    for (int i = 0; i < N; i++)
    {
        if (!isPrime[v[i]])
        {
            answer++;
        }
    }

    cout << answer << endl;

    return 0;
}