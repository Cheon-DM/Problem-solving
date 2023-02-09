package sds.DAY07.P5719;

/**
 * 최단 경로를 찾은 후 그래프에서 지워주기
 * -> 그리고 다시 다익스트라해서 그래프 탐색.
 * but. 최단 경로가 여러개 존재할 수 있으므로 이를 모두 제거할 필요가 있다.
 * 역순 인접리스트를 통해 여러 개 존재하는 최단 경로를 제거할 수 있음
 *
 * cf) K번째 최단 경로와 다른점 : 이 문제는 최단 경로를 아예 삭제해줘야한다는 특징을 가지고 있음.
 */

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class Edge implements Comparable<Edge>{
    int node;
    int time;

    public Edge(int node, int time) {
        this.node = node;
        this.time = time;
    }

    @Override
    public int compareTo(Edge o) {
        int comp1 = time - o.time;
        if (comp1 == 0) return node - o.node;
        return comp1;
    }
}

public class Main {

    static int N, M, S, D, U, V, P;
    static List<Edge>[] list;
    static int[] dist;
    static List<Integer>[] reverse;
    static boolean[][] checked; // 제거된 간선 체크 배열
    static final int INF = 100000001;

    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("src/sds/DAY07/P5719/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        while (true){
            // N(장소의 수), M(도로의 수) 입력
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());

            // 입력 종료
            if (N == 0 && M == 0) break;

            // S(시작점), D(도착점) 입력력
            st = new StringTokenizer(br.readLine());
            S = Integer.parseInt(st.nextToken());
            D = Integer.parseInt(st.nextToken());

            // list 초기화
            list = new List[N];
            for (int i = 0; i < N; i++) {
                list[i] = new ArrayList<>();
            }

            // u->v(가는 길) p(거리) 입력
            for (int i = 0; i < M; i++) {
                st = new StringTokenizer(br.readLine());
                U = Integer.parseInt(st.nextToken());
                V = Integer.parseInt(st.nextToken());
                P = Integer.parseInt(st.nextToken());

                list[U].add(new Edge(V, P));
            }

            checked = new boolean[N][N];

            Dijkstra(S);
            erase(D);
            Dijkstra(S);

            if (dist[D] == INF){
                bw.write("-1\n");
            } else {
                bw.write(dist[D] + "\n");
            }
        }

        bw.flush();
        bw.close();
        br.close();
    }

    /**
     * 현재 노드에서 다음 노드로 이동할 때 방문필수
     * 최단 경로를 삭제하기 위해서 경로를 저장할 필요 있음.
     * ->  역순으로 인접리스트 하나 더 만들기(?)
     * ->  방문이 가능하면 역순으로 인접리스트 하나 만들기
     * ->  이미 방문한 엣지가 하나 들어와서 비교했을 때, 최단 경로일 경우 역순 인접리스트 하나 더 추가
     * 만약 더 작은 최단 경로가 들어올 때, 최단 경로가 갱신되므로
     * 역순 인접리스트를 비워준 후(clear), 추가해주어야함
     */
    
    static void Dijkstra(int start){
        // dist, reverse init
        dist = new int[N];
        reverse = new List[N];
        for (int i = 0; i < N; i++) {
            dist[i] = INF;
            reverse[i] = new ArrayList<>();
        }

        PriorityQueue<Edge> pq = new PriorityQueue<>();
        dist[start] = 0;
        pq.add(new Edge(start, 0));

        while (!pq.isEmpty()) {
            Edge cur = pq.poll();
            int node = cur.node;

            for (int i = 0; i < list[node].size(); i++) {
                Edge e = list[node].get(i);
                int nextNode = e.node;
                int nCost = e.time;

                // 제거된 간선
                if (checked[node][nextNode]) continue;

                // 최단 경로 갱신
                if (dist[nextNode] > dist[node] + nCost){
                    dist[nextNode] = dist[node] + nCost;

                    // 역 추적 경로 갱신 + 추가
                    reverse[nextNode] = new ArrayList<>();
                    reverse[nextNode].add(node);

                    pq.add(new Edge(nextNode, dist[nextNode]));
                }
                // 또 다른 최단 경로 존재
                else if (dist[nextNode] == dist[node] + nCost){
                    // 역 추적 경로 추가
                    reverse[nextNode].add(node);
                    //pq.add(new Edge(nextNode, dist[nextNode]));
                }
            }
        }
    }

    static void erase(int dest){
        for (int i = 0; i < reverse[dest].size(); i++) {
            Integer src = reverse[dest].get(i);
            if (checked[src][dest]) continue;
            checked[src][dest] = true;
            erase(src);
        }
    }
}
