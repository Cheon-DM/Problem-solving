package sds.DAY08.P1932;

import java.io.*;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int[][] inputs;
    static int[][] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        inputs = new int[N][N];
        dp = new int[N][N];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j <= i; j++) {
                inputs[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        dp[0][0] = inputs[0][0];

        for (int i = 1; i < N; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0){
                    dp[i][j] = dp[i-1][j] + inputs[i][j];
                }
                else if (i == j) {
                    dp[i][j] = dp[i-1][j-1] + inputs[i][j];
                }
                else {
                    dp[i][j] = Math.max(dp[i-1][j-1], dp[i-1][j]) + inputs[i][j];
                }

            }
        }

        int max = 0;
        for (int i = 0; i < N; i++) {
            max = Math.max(max, dp[N-1][i]);
        }
        bw.write(max + "\n");
        bw.flush();
        bw.close();
        br.close();
    }
}
