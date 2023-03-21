/**
 * leetcode - 2348
 * array, math, dp
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    long long dp[100001] = {
        0,
    };

    long long countOcc(int cnt)
    {
        if (dp[cnt] != 0)
            return dp[cnt];

        for (int i = 1; i <= cnt; i++)
        {
            dp[i] = dp[i - 1] + i;
        }

        return dp[cnt];
    }

    long long zeroFilledSubarray(vector<int> &nums)
    {
        long long ans = 0;
        int size = 1;

        for (int i = 0; i < nums.size(); i++)
        {
            int cnt = 0;
            if (nums[i] == 0)
            {
                cnt++;
                while (i + 1 != nums.size() && nums[i + 1] == 0)
                {
                    cnt++;
                    i++;
                }
            }

            ans += countOcc(cnt);
        }

        return ans;
    }
};