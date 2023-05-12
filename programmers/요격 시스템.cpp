/**
 * programmers - 요격 시스템
 * sorting
 */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets)
{
    int answer = 0;

    sort(targets.begin(), targets.end());

    int idx = 0;
    while (idx < targets.size())
    {
        int e = targets[idx++][1];

        while (idx < targets.size() && e > targets[idx][0])
        {
            if (targets[idx][1] < e)
            {
                e = targets[idx][1];
            }
            idx++;
        }
        answer++;
    }

    return answer;
}