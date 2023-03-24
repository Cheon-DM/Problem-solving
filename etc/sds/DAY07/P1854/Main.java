package sds.DAY07.P1854;

import java.io.*;
import java.util.*;

class Edge implements Comparable<Edge>{
    int node;
    int cost;

    public Edge(int node, int cost) {
        this.node = node;
        this.cost = cost;
    }

    @Override
    public int compareTo(Edge o) {
        return cost - o.cost;
    }
}

public class Main {
    static int N, M, K, A, B, C;
    static List<Edge>[] list;
    static PriorityQueue<Integer>[] dist;
    static final int INF = 2000000001;

    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("src/sds/DAY07/P1854/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        // list init
        list = new List[N+1];
        dist = new PriorityQueue[N+1];
        for (int i = 0; i < N + 1; i++) {
            list[i] = new ArrayList<>();
            dist[i] = new PriorityQueue<>(K);
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            A = Integer.parseInt(st.nextToken());
            B = Integer.parseInt(st.nextToken());
            C = Integer.parseInt(st.nextToken());
            list[A].add(new Edge(B, C));
        }

        Dijkstra();

        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= N; i++) {
            if (dist[i].size() == K){
                sb.append((dist[i].peek() * -1) + "\n");
            } else {
                sb.append("-1\n");
            }
        }
        bw.write(sb.toString());

        bw.flush();
        bw.close();
        br.close();
    }

    /**
     * dist[] 각각 리스트로 달아서 거리 리스트를 만들어 놓음.
     * 작은 순으로 정렬해놓기 위해서 pq를 사용해줌.
     */

    static void Dijkstra(){
        PriorityQueue<Edge> pq = new PriorityQueue<Edge>();
        dist[1].add(0);
        pq.add(new Edge(1, 0));

        while (!pq.isEmpty()) {
            Edge cur = pq.poll();
            int start = cur.node;

            for (int i = 0; i < list[start].size(); i++) {
                Edge next = list[start].get(i);

                // 저장된 경로가 적어도 K개를 만들어놔야함.
                if (dist[next.node].size() < K) {
                    // K번째의 거리를 구하기 위해서 pq에는 K개의 거리를 남겨둘 것인데
                    // 마지막에 K번째를 뽑으려면 이를 맨 위에 올려놔야함
                    // 따라서 우선순위를 크케 줘야함.
                    dist[next.node].add((cur.cost + next.cost) * -1);
                    pq.add(new Edge(next.node, cur.cost + next.cost));
                }


                else if ((dist[next.node].peek() * -1) > cur.cost + next.cost){
                    // 현재 K번째 거리는 K+1번째 거리로 바뀌게 된다.
                    // 따라서 K+1번째 거리는 필요없으므로 poll시키고, 바뀔 값을 하나 넣어준다.
                    dist[next.node].poll();
                    dist[next.node].add((cur.cost + next.cost) * -1);
                    pq.add(new Edge(next.node, cur.cost + next.cost));
                }
            }
        }
    }
}
