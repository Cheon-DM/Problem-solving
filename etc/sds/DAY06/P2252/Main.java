package sds.DAY06.P2252;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int N, M, A, B;
    static List<Integer>[] arr;
    static int[] indegree;

    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("src/sds/DAY06/P2252/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        arr = new ArrayList[N+1];
        for (int i = 0 ; i < N+1; i++){
            arr[i] = new ArrayList<>();
        }
        indegree = new int[N+1];

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            A = Integer.parseInt(st.nextToken());
            B = Integer.parseInt(st.nextToken());

            init(A, B);
        }

        topologicalSort();
    }

    static void init(int a, int b){
        // a->b
        arr[a].add(b);
        // b의 indegree 증가
        indegree[b]++;
    }

    static void topologicalSort(){
        Queue<Integer> q = new LinkedList<>();

        // indegree가 0인 거 q에 넣기
        for (int i = 1; i <= N; i++) {
            if (indegree[i] == 0){
                q.add(i);
            }
        }

        while (!q.isEmpty()){
            int cur = q.poll();
            System.out.print(cur + " ");

            for (int i = 0; i < arr[cur].size(); i++){
                int next = arr[cur].get(i);
                indegree[next]--;

                if (indegree[next] == 0){
                    q.add(next);
                }
            }
        }
    }
}
