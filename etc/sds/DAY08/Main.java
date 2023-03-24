package sds.DAY08;

import java.io.*;
import java.util.StringTokenizer;

public class Main {

    static int N, M, X1, X2, Y1, Y2;
    static int[][] map;
    static int[][] sum;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        map = new int[N+1][N+1];
        sum = new int[N+1][N+1];
        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= N; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + map[i][j];
            }
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            X1 = Integer.parseInt(st.nextToken());
            Y1 = Integer.parseInt(st.nextToken());
            X2 = Integer.parseInt(st.nextToken());
            Y2 = Integer.parseInt(st.nextToken());

            int result = sum[X2][Y2] - sum[X1-1][Y2] - sum[X2][Y1-1] + sum[X1-1][Y1-1];
            bw.write(result + "\n");
        }
        bw.flush();
        bw.close();
        br.close();

    }
}
