package sds.DAY08.P11049;

import java.io.*;
import java.util.StringTokenizer;

class Matrix {
    int row;
    int col;

    public Matrix(int row, int col) {
        this.row = row;
        this.col = col;
    }
}

public class Main {

    static int N;
    static Matrix[] matrix;
    static int[][] dp;
    static final int INF = 1000000000;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;
        N = Integer.parseInt(br.readLine());
        matrix = new Matrix[N];
        dp = new int[N][N];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int r = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            matrix[i] = new Matrix(r, c);
        }

        for (int i = 1; i < N; i++) { // 대각선 줄
            for (int j = 0; i+j < N; j++) { // 대각선 항목
                int x = i + j; //
                dp[j][x] = INF;

                for (int k = j; k < x; k++) {
                    dp[j][x] = Math.min(dp[j][x], dp[j][k] + dp[k + 1][x] + (matrix[j].row * matrix[k].col * matrix[x].col));
                }
            }
        }

        StringBuilder sb = new StringBuilder();
        sb.append(dp[0][N - 1]);
        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();
    }
}
