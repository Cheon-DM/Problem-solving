package sds.DAY07.P11400;

import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

class Edge implements Comparable<Edge>{
    int from;
    int to;

    public Edge(int from, int to) {
        this.from = from;
        this.to = to;
    }

    @Override
    public int compareTo(Edge o) {
        int comp1 = from - o.from;
        if (comp1 == 0){
            return to - o.to;
        }
        return comp1;
    }
}

public class Main {

    static int V, E, A, B;
    static List<Integer>[] links;
    static int[] orders;
    static List<Edge> answer;
    static int level = 1;

    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("src/sds/DAY07/P11400/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        V = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());

        links = new List[V+1];
        orders = new int[V+1];
        answer = new ArrayList<>();
        for (int i = 1; i <= V; i++) {
            links[i] = new ArrayList<>();
        }

        for (int i = 0; i < E; i++) {
            st = new StringTokenizer(br.readLine());
            A = Integer.parseInt(st.nextToken());
            B = Integer.parseInt(st.nextToken());

            links[A].add(B);
            links[B].add(A);
        }

        for (int i = 1; i <= V; i++) {
            if (orders[i] == 0){
                dfs(i, 0);
            }
        }

        Collections.sort(answer);
        StringBuilder sb = new StringBuilder();
        int len = answer.size();
        sb.append(len + "\n");
        for (int i = 0; i < answer.size(); i++) {
            sb.append(answer.get(i).from);
            sb.append(" ");
            sb.append(answer.get(i).to);
            sb.append("\n");
        }
        bw.write(sb.toString());

        bw.flush();
        bw.close();
        br.close();
    }

    /**
     * 1. 자기 부모 노드의 order 계산은 안해줘도 됨 (low 계산 시)
     * 2. 사이클을 고려해야함
     * 3. order < low 단절점, 점의 경우에는 사이클 고려 x
     * 4. 루트 노드일 때 child
     */

    static int dfs(int start, int parent){
        // 현재 자신의 단계 저장
        orders[start] = level++;
        // 현재 order
        int ret = orders[start];

        for (int i = 0; i < links[start].size(); i++) {
            // 다음 정점
            int next = (int) links[start].get(i);

            // 사이클 고려
            if (next == parent) continue;

            // 이미 방문한 자식 -> 현재 order 비교 필요
            if (orders[next] != 0) {
                ret = Math.min(ret, orders[next]);
                continue;
            }

            // 다음 정점의 order, start가 next의 부모(전 단계)
            int low = dfs(next, start);

            if (low > ret){ // 단절선 가능
                answer.add(new Edge(Math.min(start, next), Math.max(start, next)));
            }

            // 현재 order과 자식 order 비교
            ret = Math.min(ret, low);
        }

        return ret;
    }
}
