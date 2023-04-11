/**
 * programmers - 최고의 집합
 * math
 */

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s)
{
    vector<int> answer;

    if (n > s)
    {
        answer.push_back(-1);
        return answer;
    }

    int num = n;
    for (int i = 0; i < n - 1; i++)
    {
        int tmp = s / num;
        answer.push_back(s / num);
        s -= tmp;
        num--;
    }

    answer.push_back(s);

    return answer;
}