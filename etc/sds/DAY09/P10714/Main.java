package sds.DAY09.P10714;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Main {

    static int N;
    static int[] cake;
    static long[][] dp;

    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("src/sds/DAY09/P10714/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        N = Integer.parseInt(br.readLine());

        cake = new int[N+1];
        dp = new long[N+1][N+1];
        for (int i = 1; i <= N; i++) {
            cake[i] = Integer.parseInt(br.readLine());
            if (N % 2 == 1){
                dp[i][i] = cake[i];
            }
        }

        long ans = 0;
        for (int k = 0; k < N; k++) {
            dp = new long[N+1][N+1];
            for (int i = 1; i <= N; i++) {
                if (N % 2 == 0){
                    dp[i][i] = cake[to(i+k)];
                }
            }

            for (int i = 1; i < N; i++) {
                for (int start = 1; start + i <= N; start++) {
                    int end = start + i;

                    // JOI 차례 - 최대
                    if ((N - (end-start)) % 2 == 0){
                        dp[start][end] = Math.max(dp[start+1][end] + cake[to(start + k)], dp[start][end-1] + cake[to(end + k)]);
                    }

                    // IOI 차례 - IOI가 최대로 먹을 것이므로 이전 이전 dp에서는 최소
                    else {
                        dp[start][end] = Math.min(dp[start + 1][end], dp[start][end -1]);
                    }
                }
            }

            ans = Math.max(ans, dp[1][N]);
        }

        System.out.println(ans);
    }

    static int from(int from) {
        if (from < 1) return N;
        else return from;
    }

    static int to(int to) {
        if (to > N) return 1;
        else return to;
    }
}
