package programmers.네트워크;

import org.junit.Assert;
import org.junit.Test;

public class Solution {

    public int solution(int n, int[][] computers) {
        int answer = 0;

        boolean[] visited = new boolean[n];

        for (int i = 0; i < n; i++){
            if (!visited[i]){
                dfs(i, computers, visited);
                answer++;
            }
        }

        return answer;
    }

    public void dfs(int start, int[][] computers, boolean[] visited){
        for (int i = 0; i < computers.length; i++){
            if (start != i){
                if (computers[start][i] == 1 && !visited[i]){
                    visited[i] = true;
                    dfs(i, computers, visited);
                }
            }
        }
    }

    @Test
    public void 정답(){
        Assert.assertEquals(2, solution(3, new int[][]{{1, 1, 0}, {1, 1, 0}, {0, 0, 1}}));
        Assert.assertEquals(1, solution(3, new int[][]{{1, 1, 0}, {1, 1, 1}, {0, 1, 1}}));
    }
}
