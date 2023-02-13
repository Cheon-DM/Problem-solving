package sds.DAY09.P11062;

import java.io.*;
import java.util.StringTokenizer;

public class Main {

    static int T, N;
    static int[] inputs;
    static int[][] dp;

    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("src/sds/DAY09/P11062/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        T = Integer.parseInt(br.readLine());

        // testcase
        for (int t = 0; t < T; t++) {
            N = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine());

            inputs = new int[N+1];
            dp = new int[N+1][N+1];
            for (int i = 1; i <= N; i++) {
                inputs[i] = Integer.parseInt(st.nextToken());
                if (N % 2 == 1){ // N이 홀수면 근우로 끝나고, N이 짝수면 명우로 끝남
                    dp[i][i] = inputs[i];
                }
            }

            for (int i = 1; i < N; i++) {
                for (int start = 1; i + start <= N; start++) {
                    int end = i + start;

                    // 근우 -> 최대한 큰 값을 뽑음
                    if ((N-(end-start+1)) % 2 == 0){
                        dp[start][end] = Math.max(dp[start+1][end] + inputs[start], dp[start][end-1] + inputs[end]);
                    }

                    // 명우 -> 최소한의 값을 뽑음
                    else {
                        dp[start][end] = Math.min(dp[start+1][end], dp[start][end-1]);
                    }
                }
            }

            bw.write(dp[1][N] + "\n");
        }

        bw.flush();
        bw.close();
        br.close();
    }
}
