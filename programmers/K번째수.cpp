/**
 * programmers - K번째수
 * sorting
 */

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;

    for (int i = 0; i < commands.size(); i++)
    {
        int s = commands[i][0];
        int e = commands[i][1];

        vector<int> sub;
        sub.assign(array.begin() + s - 1, array.begin() + e);
        sort(sub.begin(), sub.end());
        answer.push_back(sub[commands[i][2] - 1]);
    }

    return answer;
}