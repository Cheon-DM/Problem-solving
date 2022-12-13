'''
' leetcode - 931
' array, DP, matrix
'''

class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        size = len(matrix[0])
        dp = [[0]*size for _ in range(size)]
        for i in range(size):
            dp[0][i] = matrix[0][i]
        
        for i in range(1, size):
            for j in range(size):
                dp[i][j] = matrix[i][j]
                if j == 0:
                    dp[i][j] += min(dp[i-1][j], dp[i-1][j+1])
                elif j == size-1:
                    dp[i][j] += min(dp[i-1][j-1], dp[i-1][j])
                else:
                    dp[i][j] += min(dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1])
        
        answer = min(dp[size-1])
        return answer