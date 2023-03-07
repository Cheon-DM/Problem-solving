/**
 * programmers - 최소직사각형
 * brute force
 */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> card)
{
    int answer = 0;

    // 왼쪽에 큰 수 놔두기
    int max_l = 0, max_r = 0;
    for (int i = 0; i < card.size(); i++)
    {
        if (card[i][0] < card[i][1])
        {
            // swap
            int tmp = card[i][0];
            card[i][0] = card[i][1];
            card[i][1] = tmp;
        }

        max_l = max(max_l, card[i][0]);
        max_r = max(max_r, card[i][1]);
    }

    answer = max_l * max_r;

    return answer;
}