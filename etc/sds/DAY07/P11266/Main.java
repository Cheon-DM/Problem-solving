package sds.DAY07.P11266;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static int V, E, A, B;
    static List<Integer>[] links;
    static int[] order;
    static boolean[] checked; // 단절점 가능한 점 체크
    static int num = 1;

    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("src/sds/DAY07/P11266/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        V = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());
        links = new List[V+1];
        order = new int[V+1];
        checked = new boolean[V+1];
        for (int i = 0; i <= V; i++) {
            links[i] = new ArrayList<>();
        }

        for (int i = 0; i < E; i++) {
            st = new StringTokenizer(br.readLine());
            A = Integer.parseInt(st.nextToken());
            B = Integer.parseInt(st.nextToken());

            links[A].add(B);
            links[B].add(A);
        }

        for (int i = 1; i <= V; i++){
            if (order[i] == 0){
                // 모든 그래프가 다 연결된 것이 아니므로 dfs를 다 돌려봄
                dfs(i, true);
            }
        }

        int total = 0;
        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= V; i++) {
            if (checked[i]) {
                total++;
                sb.append(i);
                sb.append(" ");
            }
        }
        System.out.println(total);
        System.out.println(sb.toString());
    }

    static int dfs(int cur, boolean isRoot){
        order[cur] = num++;

        int child = 0; // 자식
        int curLow = order[cur]; // 현재 order low

        for (int i = 0; i < links[cur].size(); i++){
            int next = links[cur].get(i);

            if (order[next] == 0){ // 자식 방문 X
                child++;
                int nextLow = dfs(next, false);

                // 시작 정점이 아니면서 nextLow가 현재 order보다 큰 경우 단절점 가능
                if (!isRoot && nextLow >= order[cur]) {
                    checked[cur] = true;
                }

                curLow = Math.min(curLow, nextLow);

            } else { // 이미 자식 방문 함
                curLow = Math.min(curLow, order[next]);
            }
        }

        // root인 경우
        if (isRoot && child >= 2){
            checked[cur] = true;
        }

        return curLow;
    }
}
