package sds.DAY07.P11657;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

class Edge {
    int start;
    int end;
    int time;

    public Edge(int start, int end, int time) {
        this.start = start;
        this.end = end;
        this.time = time;
    }
}

public class Main {

    static int N, M, A, B, C;
    static List<Edge> inputs;
    static long[] dist;
    static final int MAX = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("src/sds/DAY07/P11657/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        inputs = new ArrayList<>();
        dist = new long[N+1];
        for (int i = 0; i < N + 1; i++) {
            dist[i] = MAX;
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            A = Integer.parseInt(st.nextToken());
            B = Integer.parseInt(st.nextToken());
            C = Integer.parseInt(st.nextToken());

            inputs.add(new Edge(A, B, C));
        }

        boolean flag = BellmanFord(1);
        StringBuilder sb = new StringBuilder();
        if (flag){
            for (int i = 2; i <= N; i++) {
                if (dist[i] == MAX) {
                    sb.append(-1);
                } else {
                    sb.append(dist[i]);
                }
                sb.append("\n");
            }
            System.out.println(sb.toString());
        } else {
            System.out.println(-1);
        }
    }

    static boolean BellmanFord(int start){
        dist[start] = 0;

        for (int i = 1; i <= N; i++){
            for (int j = 0; j < M; j++) {
                Edge cur = inputs.get(j);
                int from = cur.start;
                int to = cur.end;
                int cost = cur.time;

                if (dist[from] != MAX && dist[to] > dist[from] + cost) {
                    dist[to] = dist[from] + cost;

                    if (i == N){ // 음수 cycle 존재
                        return false;
                    }
                }
            }
        }
        return true;
    }
}
