/**
 * programmers - 체육복
 * greedy
 */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = 0;
    n -= lost.size();

    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    for (int i = 0; i < lost.size(); i++)
    {
        for (int j = 0; j < reserve.size(); j++)
        {
            if (lost[i] == reserve[j])
            {
                lost.erase(lost.begin() + i);
                i--;
                reserve.erase(reserve.begin() + j);
                j--;
                n++;
            }
        }
    }

    for (int i = 0; i < lost.size(); i++)
    {
        for (int j = 0; j < reserve.size(); j++)
        {
            if (lost[i] - 1 == reserve[j])
            {
                lost.erase(lost.begin() + i);
                i--;
                reserve.erase(reserve.begin() + j);
                n++;
                break;
            }

            if (lost[i] + 1 == reserve[j])
            {
                lost.erase(lost.begin() + i);
                i--;
                reserve.erase(reserve.begin() + j);
                n++;
                break;
            }
        }
    }

    answer = n;

    return answer;
}