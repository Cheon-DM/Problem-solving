/**
 * programmers - 가장 큰 수
 * sorting
 */

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(string a, string b)
{
    string tmp1 = "", tmp2 = "";
    tmp1 = a + b;
    tmp2 = b + a;

    if (tmp1 > tmp2)
        return 1;
    else
        return 0;
}

string solution(vector<int> numbers)
{
    string answer = "";

    vector<string> numStr;
    // 숫자 배열을 문자 배열로 바꾼 후, 내림차순 정렬 필요
    for (int i = 0; i < numbers.size(); i++)
    {
        numStr.push_back(to_string(numbers[i]));
    }

    sort(numStr.begin(), numStr.end(), cmp);

    for (int i = 0; i < numStr.size(); i++)
    {

        answer += numStr[i];
    }

    if (answer[0] == '0')
    {
        answer = "0";
    }

    return answer;
}