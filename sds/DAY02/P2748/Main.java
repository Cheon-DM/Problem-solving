package sds.DAY02.P2748;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int n;
    static long[] dp;

    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("src/sds/DAY02/P2748/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        dp = new long[91];

        // 이미 아는 값
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        System.out.println(dp[n]);
    }
}
