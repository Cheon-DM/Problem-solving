/**
 * programmers - H-Index
 * sorting
 */

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations)
{
    int answer = 0;

    sort(citations.begin(), citations.end());

    int h = 0;
    int idx = 0;
    while (idx < citations.size())
    {
        if (h > citations[idx])
        {
            idx++;
            continue;
        }

        int cnt = citations.size() - idx;

        if (cnt >= h)
        {
            answer = h;
        }
        else
        {
            break;
        }

        h++;
    }

    return answer;
}