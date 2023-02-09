package sds.DAY06.P2458;

/**
 * 플로이드 워셜을 사용해 모든 정점이 이동할 수 있는 길을 구한 후,
 * 각 정점이 갈 수 있고, 올 수 있는 정점의 개수가 V-1이면 자신의 등수를 알 수 있음.
 * (floyd 최대 500으로 생각하기)
 */

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static int N, M, A, B;
    static int[][] dist;
    static final int INF = 1000;

    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("src/sds/DAY06/P2458/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        dist = new int[N+1][N+1];
        for (int i = 1; i < N + 1; i++) {
            for (int j = 1; j < N + 1; j++) {
                if (i == j) dist[i][j] = 0;
                else dist[i][j] = INF;
            }
        }

        for (int i = 0; i < M; i++){
            st = new StringTokenizer(br.readLine());
            A = Integer.parseInt(st.nextToken());
            B = Integer.parseInt(st.nextToken());

            dist[A][B] = 1;
        }

        floyd();

        int[] result = new int[N+1];
        for (int i = 1; i < N + 1; i++) {
            for (int j = 1; j < N + 1; j++) {
                if (i != j){
                    if (dist[i][j] != INF && dist[i][j] > 0) {
                        result[i]++;
                        result[j]++;
                    }
                }
            }
        }

        int cnt = 0;
        for (int i = 1; i < N + 1; i++) {
            if (result[i] == N-1) cnt++;
        }
        bw.write(cnt + "\n");

        bw.flush();
        bw.close();
        br.close();
    }

    static void floyd(){
        for (int k = 1; k < N + 1; k++) {
            for (int i = 1; i < N + 1; i++) {
                for (int j = 1; j < N + 1; j++) {
                    dist[i][j] = Math.min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
    }
}
