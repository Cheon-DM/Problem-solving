package sds.DAY09.P9252;

import java.io.*;

public class Main {

    static String str1, str2;
    static int[][] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        str1 = br.readLine();
        str2 = br.readLine();

        dp = new int[str1.length()+1][str2.length()+1];

        for (int i = 1; i <= str1.length(); i++) {
            for (int j = 1; j <= str2.length(); j++) {
                if (str1.charAt(i-1) == str2.charAt(j-1)){
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        int ans = dp[str1.length()][str2.length()];

        if (ans == 0){
            bw.write(ans + "\n");
        } else {
            bw.write(ans + "\n");

            StringBuilder sb = new StringBuilder();
            int l1 = str1.length();
            int l2 = str2.length();
            while (true){
                if (l1 == 0 || l2 == 0) break;

                if (str1.charAt(l1-1) == str2.charAt(l2-1)){
                    String tmp = sb.toString();
                    sb = new StringBuilder();
                    sb.append(str1.charAt(l1-1) + tmp);
                    l1--;
                    l2--;
                }

                else {
                    if (dp[l1-1][l2] > dp[l1][l2-1]){
                        l1--;
                    } else {
                        l2--;
                    }
                }
            }

            bw.write(sb.toString() + "\n");
        }

        bw.flush();
        bw.close();
        br.close();
    }
}
