package sds.DAY07.P11404;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int N, M, A, B, C;
    static int[][] dist;
    static final int INF = 10000001;

    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("src/sds/DAY07/P11404/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());
        dist = new int[N+1][N+1];
        for (int i = 1; i < N + 1; i++) {
            for (int j = 1; j < N + 1; j++) {
                dist[i][j] = INF;
            }
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            A = Integer.parseInt(st.nextToken());
            B = Integer.parseInt(st.nextToken());
            C = Integer.parseInt(st.nextToken());
            // a -> b 가는데 dis = c;
            dist[A][B] = Math.min(dist[A][B], C);
        }

        floyd();
        for (int i = 1; i < N + 1; i++) {
            StringBuilder sb = new StringBuilder();
            for (int j = 1; j < N + 1; j++) {
                if (dist[i][j] == INF){
                    sb.append(0).append(" ");
                } else {
                    sb.append(dist[i][j]).append(" ");
                }
            }
            System.out.println(sb.toString());
        }
    }

    static void floyd(){
        for (int k = 1; k <= N; k++) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    if (k != i && k != j && i != j){
                        dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
    }
}
