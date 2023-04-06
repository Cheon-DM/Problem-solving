/**
 * programmers - 다음 큰 숫자
 * math
 */

#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    int answer = 0;

    // 주어진 n을 2진수로 바꿔 1의 개수 구하기
    int cnt1 = 0;
    int tmp = n;
    while (tmp)
    {
        cnt1 += (tmp % 2);
        tmp /= 2;
    }

    int second = n + 1;
    while (1)
    {
        int cnt2 = 0;
        tmp = second;

        while (tmp)
        {
            cnt2 += (tmp % 2);
            tmp /= 2;
        }

        if (cnt1 == cnt2)
        {
            answer = second;
            break;
        }

        second++;
    }

    return answer;
}