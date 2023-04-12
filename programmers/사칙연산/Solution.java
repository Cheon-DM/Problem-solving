package programmers.사칙연산;

import org.junit.Assert;
import org.junit.Test;

import java.util.ArrayList;
import java.util.List;

public class Solution {

    final int INF = 987654321;
    List<Integer> num = new ArrayList<>();
    List<String> operation = new ArrayList<>();
    int[][][] dp;

    public int solution(String arr[]) {
        int answer = -1;

        for (int i = 0; i < arr.length; i++) {
            if (i % 2 == 0){
                num.add(Integer.valueOf(arr[i]));
            }
            else {
                operation.add(arr[i]);
            }
        }

        int n = arr.length / 2;
        dp = new int[2][200][200]; // dp[0][i][j] = 최솟값, dp[1][i][j] = 최댓값
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                dp[0][i][j] = INF;
                dp[1][i][j] = -INF;
            }
        }
        answer = func(0, n, 1);

        return answer;
    }

    public int func(int s, int e, int isMax){
        if (s == e){
            dp[isMax][s][e] = num.get(s);
            return dp[isMax][s][e];
        }

        if (dp[isMax][s][e] != INF && dp[isMax][s][e] != -INF){
            return dp[isMax][s][e];
        }

        dp[isMax][s][e] = 0;

        int result = isMax == 1 ? -INF : INF;

        if (isMax == 1){
            for (int m = s; m < e; m++){
                if (operation.get(m).equals("-")){
                    // a - b 가 최댓값 : a는 최대, b는 최소
                    result = Math.max(result, func(s, m, 1) - func(m+1, e, 0));
                }
                else {
                    // a + b 가 최댓값 : a,b 모두 최대
                    result = Math.max(result, func(s, m, 1) + func(m+1, e, 1));
                }
            }
        }

        else {
            for (int m = s; m < e; m++){
                if (operation.get(m).equals("-")){
                    // -(a - b) 가 최댓값 : a는 최소, b는 최대
                    result = Math.min(result, func(s, m, 0) - func(m+1, e, 1));
                }
                else {
                    // -(a + b) 가 최댓값 : a,b 모두 최소
                    result = Math.min(result, func(s, m, 0) + func(m+1, e, 0));
                }
            }
        }

        dp[isMax][s][e] = result;
        return dp[isMax][s][e];
    }

    @Test
    public void 테스트케이스1(){
        Assert.assertEquals(1, solution(new String[]{"1", "-", "3", "+", "5", "-", "8"}));
    }

    @Test
    public void 테스트케이스2(){
        Assert.assertEquals(3, solution(new String[]{"5", "-", "3", "+", "1", "+", "2", "-", "4"}));
    }

    @Test
    public void 테스트케이스3(){
        Assert.assertEquals(-4, solution(new String[]{"5", "-", "10", "+", "1", "+", "2", "-", "4"}));
    }
}
