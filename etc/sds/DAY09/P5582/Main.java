package sds.DAY09.P5582;

import java.io.*;

public class Main {

    static String S1, S2;
    static int[][] dp;

    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("src/sds/DAY09/P5582/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        S1 = br.readLine();
        S2 = br.readLine();

        int s1Len = S1.length();
        int s2Len = S2.length();

        dp = new int[s1Len + 1][s2Len + 1];

        int ans = 0;
        for (int i = 1; i < s1Len + 1; i++) {
            for (int j = 1; j < s2Len + 1; j++) {
                if (S1.charAt(i-1) == S2.charAt(j-1)){
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = 0;
                }

                ans = Math.max(ans, dp[i][j]);
            }
        }

        bw.write(ans + "\n");
        bw.flush();
        bw.close();
        br.close();
    }
}
