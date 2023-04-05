/**
 * programmers - 조이스틱
 * greedy
 */

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string name)
{
    int answer = 0;
    int shift = name.size() - 1; // 커서를 좌, 우 한방향으로 이도

    for (int i = 0; i < name.size(); i++)
    {
        if (name[i] == 'A')
        {
            int target = i;
            while (target < name.size() && name[target] == 'A')
            {
                target++;
            }

            int left = i == 0 ? 0 : i - 1;
            int right = name.size() - target;

            shift = min(shift, left + right + min(left, right));
        }
    }

    answer += shift;

    for (auto a : name)
    {
        answer += min(a - 'A', 'Z' - a + 1);
    }

    return answer;
}