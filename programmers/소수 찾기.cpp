/**
 * programmers - 소수 찾기
 * prime, dfs
 */

#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

#define MAX 10000000
using namespace std;

int strSize;
vector<string> nums;
bool visited[8] = {
    false,
};
bool prime[MAX] = {
    false,
};

void getPrime()
{
    prime[0] = true;
    prime[1] = true;

    for (int i = 2; i <= sqrt(MAX); i++)
    {
        if (!prime[i])
        {
            for (int j = i * 2; j <= MAX; j += i)
            {
                prime[j] = true;
            }
        }
    }
}

set<int> s;

void dfs(string num)
{

    // 목적지인가?
    if (num.size() > 0 && num.size() <= strSize)
    {
        if (!prime[stoi(num)])
        {
            s.insert(stoi(num));
        }
    }

    for (int i = 0; i < strSize; i++)
    {
        if (!visited[i])
        {
            // 체크인
            visited[i] = true;

            // 간다
            dfs(num + nums[i]);

            // 체크아웃
            visited[i] = false;
        }
    }
}

int solution(string numbers)
{
    int answer = 0;
    strSize = numbers.size();

    for (int i = 0; i < numbers.size(); i++)
    {
        nums.push_back(numbers.substr(i, 1));
    }

    sort(nums.begin(), nums.end());
    getPrime();
    dfs("");

    answer = s.size();

    return answer;
}