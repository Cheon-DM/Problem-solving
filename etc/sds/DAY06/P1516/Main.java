package sds.DAY06.P1516;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int N;
    static List<Integer>[] links;
    static int[] indegree, costs;
    static int[] answer;

    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("src/sds/DAY06/P1516/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());

        // init
        links = new ArrayList[N+1];
        indegree = new int[N+1];
        costs = new int[N+1];
        answer = new int[N+1];
        for (int i = 1; i <= N; i++){
            links[i] = new ArrayList<>();
        }

        for (int i = 1; i <= N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int cost = Integer.parseInt(st.nextToken());
            costs[i] = cost;

            while (true){
                int build = Integer.parseInt(st.nextToken());

                if (build == -1) break;

                links[build].add(i);
                indegree[i]++;
            }
        }
        
        topologicalSort();

        for (int i = 1; i <= N; i++) {
            System.out.println(answer[i]);
        }
    }

    static void topologicalSort(){
        Queue<Integer> q = new LinkedList<>();

        for (int i = 1; i <= N; i++){
            if (indegree[i] == 0){
                q.add(i);
                answer[i] = costs[i];
            }
        }

        while (!q.isEmpty()){
            int cur = q.poll();

            for (int i = 0; i < links[cur].size(); i++){
                int next = links[cur].get(i);
                indegree[next]--;

                // 다음 단계 계산 시 오래 걸리는 시간 저장 (이미 저장된 시간이 더 오래걸릴 수도 있음)
                answer[next] = Math.max(answer[next], answer[cur] + costs[next]);

                if (indegree[next] == 0){
                    q.add(next);
                }
            }
        }
    }
}
