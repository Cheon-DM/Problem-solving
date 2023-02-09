package sds.DAY08.P2579;

import java.io.*;

public class Main {

    static int N;
    static int[] inputs;
    static int[] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        N = Integer.parseInt(br.readLine());
        inputs = new int[N+1];
        dp = new int[N+1];
        for (int i = 1; i <= N; i++) {
            inputs[i] = Integer.parseInt(br.readLine());
        }

        dp[1] = inputs[1];
        if (N >= 2) dp[2] = dp[1] + inputs[2];
        for (int i = 3; i <= N; i++) {
            dp[i] = Math.max(dp[i - 2] + inputs[i], dp[i - 3] + inputs[i - 1] + inputs[i]);
        }

        StringBuilder sb = new StringBuilder();
        sb.append(dp[N]);
        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();
    }
}
