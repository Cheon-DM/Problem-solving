package programmers.등굣길;

import org.junit.Assert;
import org.junit.Test;

class Solution {
    
    public int solution(int m, int n, int[][] puddles) {
        int answer = 0;
        final int MOD = 1000000007;
        
        int[][] dp = new int[n+1][m+1];
        dp[1][1] = 1;
        
        // 돌 표시
        for (int i = 0; i < puddles.length; i++){
            int s = puddles[i][1];
            int e = puddles[i][0];
            dp[s][e] = -1;
        }
        
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <=m; j++){
                if (dp[i][j] == -1) continue;
                
                if (dp[i-1][j] > 0) {
                    dp[i][j] += dp[i-1][j] % MOD;
                }
                if (dp[i][j-1] > 0){
                    dp[i][j] += dp[i][j-1] % MOD;
                }
            }
        }
        
        answer = dp[n][m] % MOD;
        
        return answer;
    }

    @Test
    public void 정답(){
        Assert.assertEquals(4, solution(4, 3, new int[][]{{2, 2}}));
    }
}