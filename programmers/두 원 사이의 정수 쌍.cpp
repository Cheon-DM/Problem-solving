/**
 * programmers - 두 원 사이의 정수 쌍
 * math
 */

#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int r1, int r2)
{
    long long answer = 0;

    long long d1 = (long long)r1 * (long long)r1;
    long long d2 = (long long)r2 * (long long)r2;

    for (long long i = 0; i < r2; i++)
    {
        if (i == 0)
        {
            answer += r2 - r1 + 1;
        }

        else if (i >= r1)
        {
            double a = sqrt(d2 - i * i);
            answer += (int)floor(a);
        }

        else
        {
            long long ii = i * i;
            double a1 = sqrt(d1 - ii);
            double a2 = sqrt(d2 - ii);

            int f = (int)floor(a2);
            int c = (int)ceil(a1);
            answer += f - c + 1;
        }
    }

    return 4 * answer;
}