/**
 * programmers - 카펫
 * brute force, math
 */

#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> solution(int brown, int yellow)
{
    vector<int> answer;

    vector<int> divisor;
    long long area = brown + yellow;

    for (int i = 1; i <= sqrt(area); i++)
    {
        if (area % i == 0)
        {
            divisor.push_back(i);
        }
    }

    sort(divisor.begin(), divisor.end());

    int w, h;
    for (int i = 0; i < divisor.size(); i++)
    {
        h = divisor[i];
        w = area / h;
        if ((w - 2) * (h - 2) == yellow)
        {
            answer.push_back(w);
            answer.push_back(h);
            break;
        }
    }

    return answer;
}