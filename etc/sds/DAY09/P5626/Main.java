package sds.DAY09.P5626;

import java.io.*;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int[] inputs;
    static int[][] dp;
    static final int MOD = 1000000007;

    /**
     * 문제 이해 X...
     * dp[i] = i번째 제단까지 나올 수 있는 경우
     *
     * N열짜리 제단은 변화를 1씩만 <br>
     * 높이를 사용해 dp[i][h] = i번째 제단까지 나올 수 있는 경우의 수 (단, 높이가 h일 때)
     * dp[i][h] = dp[i-1][h-1] + dp[i-1][h] + dp[i-1][h+1]
     * 어느 i에서 올라갈 수 있는 최대 높이가 있음. 그 최대 높이 제한을 구해 h를 제한해줘야함.
     * i에 따른 최대 높이 제한 min(N-1-i, i) 이 이상으로 올라가지 말아라.
     * i가 마지막(N) h = 0의 값을 출력
     */

    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("src/sds/DAY09/P5626/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        N = Integer.parseInt(br.readLine());
        inputs = new int[N];
        dp = new int[N][];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            inputs[i] = Integer.parseInt(st.nextToken());
        }
    }
}
