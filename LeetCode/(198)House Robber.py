'''
' leetcode - 198
' array, DP
'''

class Solution:
    def rob(self, nums: List[int]) -> int:
        size = len(nums)
        dp = [nums[0]]
        if size == 1:
            return dp[0]
        dp.append(max(nums[0], nums[1]))
        for i in range(2, size):
            dp.append(max(dp[i-2]+nums[i], dp[i-1]))
        return dp[size-1]