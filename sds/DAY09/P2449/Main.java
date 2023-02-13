package sds.DAY09.P2449;

import java.io.*;
import java.util.StringTokenizer;

public class Main {

    static int N, K;
    static int[] inputs;
    static int[][] dp;
    static final int MAX = Integer.MAX_VALUE / 2;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        inputs = new int[N+1];
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            inputs[i] = Integer.parseInt(st.nextToken());
            if (inputs[i] == inputs[i-1]){
                N--;
                i--;
            }
        }

        dp = new int[N+1][N+1];
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                dp[i][j] = MAX;
            }
            dp[i][i] = 0;
        }


        for (int i = 2; i <= N; i++) {
            for (int j = 1; i+j <= N+1; j++) {
                int x = i + j -1 ;

                for (int k = j; k < x; k++) {
                    int tmp = (inputs[j] == inputs[k+1] ? 0 : 1);
                    dp[j][x] = Math.min(dp[j][x], dp[j][k] + dp[k + 1][x] + tmp);
                }
            }
        }
        bw.write(dp[1][N] + "\n");
        bw.flush();
        bw.close();
        br.close();
    }
}
