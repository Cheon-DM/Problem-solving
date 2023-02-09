package sds.DAY07.P1753;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class Pair implements Comparable<Pair>{
    int edge;
    int cost;

    public Pair(int edge, int cost) {
        this.edge = edge;
        this.cost = cost;
    }

    @Override
    public int compareTo(Pair o) {
        int comp1 = cost - o.cost;
        if (comp1 == 0){
            return edge - o.edge;
        }
        return comp1;
    }
}

public class Main {

    static int V, E, K;
    static int u, v, w;
    static List<Pair>[] inputs;
    static PriorityQueue<Pair> pq = new PriorityQueue<>();
    static int[] dist;
    static final int MAX = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("src/sds/DAY07/P1753/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        V = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(br.readLine());

        // init
        inputs = new List[V+1];
        dist = new int[V+1];
        for (int i = 0; i <= V; i++) {
            inputs[i] = new ArrayList<>();
        }
        for (int i = 1; i <= V; i++){
            dist[i] = MAX;
        }

        for (int i = 0; i < E; i++){
            st = new StringTokenizer(br.readLine());
            u = Integer.parseInt(st.nextToken());
            v = Integer.parseInt(st.nextToken());
            w = Integer.parseInt(st.nextToken());

            inputs[u].add(new Pair(v, w));
        }

        dijkstra(K);

        for (int i = 1; i <= V; i++) {
            if (dist[i] == MAX) {
                System.out.println("INF");
            } else {
                System.out.println(dist[i]);
            }
        }
    }

    static void dijkstra(int start){
        dist[start] = 0;
        pq.add(new Pair(start, 0));

        while (!pq.isEmpty()){
            Pair p = pq.poll();
            int cur = p.edge;
            int curCost = p.cost;

            for (int i = 0; i < inputs[cur].size(); i++){
                int next = inputs[cur].get(i).edge;
                int nCost = curCost + inputs[cur].get(i).cost;

                if (nCost < dist[next]){
                    dist[next] = nCost;
                    pq.add(new Pair(next, nCost));
                }
            }
        }
    }
}
