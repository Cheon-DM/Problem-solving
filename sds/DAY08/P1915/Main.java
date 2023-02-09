package sds.DAY08.P1915;

import java.io.*;
import java.util.StringTokenizer;

public class Main {

    static int n, m;
    static int[][] inputs;
    static int[][] dp;

    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("src/sds/DAY08/P1915/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        inputs = new int[n+1][m+1];
        dp = new int[n+1][m+1];

        for (int i = 1; i <= n; i++) {
            String str = br.readLine();
            for (int j = 1; j <= m; j++) {
                inputs[i][j] = str.charAt(j-1) - '0';
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (inputs[i][j] == 1){ // 1여야만 정사각형 가능
                    if (i == 1 && j == 1){
                        dp[1][1] = 1;
                    }
                    else { // 왼쪽 위, 위, 왼쪽의 dp 확인하여 정사각형이 가능한 한 변의 최소 길이 받아온 후 + 1
                        dp[i][j] = Math.min(dp[i - 1][j - 1], Math.min(dp[i - 1][j], dp[i][j - 1])) + 1;
                    }
                    ans = Math.max(ans, dp[i][j]);
                }
            }
        }

        bw.append(ans * ans + "\n");
        bw.flush();
        bw.close();
        br.close();
    }
}
