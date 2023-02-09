package sds.DAY06.P11438;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static int N, M;
    static List<Integer>[] link;
    static int[] depth;
    static boolean[] checked;
    static int[][] parent;
    static int answer;

    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("src/sds/DAY06/P11438/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        link = new ArrayList[N+1];
        depth = new int[N+1];
        checked = new boolean[N+1];
        parent = new int[18][N+1]; // 10만 데이터는 2^17까지 필요

        for (int i = 0; i <= N; i++){
            link[i] = new ArrayList<>();
        }

        for (int i = 0; i < N-1; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            link[a].add(b);
            link[b].add(a);
        }

        setDepth(1, 0);
        setParent();

        M = Integer.parseInt(br.readLine());

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            LCA(a, b);
            System.out.println(answer);
        }
    }

    static void setDepth(int cur, int dep){
        checked[cur] = true;
        depth[cur] = dep;

        for (int i = 0; i < link[cur].size(); i++){
            int dest = link[cur].get(i);

            if (!checked[dest]){
                parent[0][dest] = cur; // dest의 바로 위 조상 = cur
                setDepth(dest, dep+1);
            }
        }
    }

    static void setParent(){
        for (int i = 1; i <= 17; i++){
            for (int j = 1; j <= N; j++){
                parent[i][j] = parent[i-1][parent[i-1][j]];
            }
        }
    }

    static void LCA(int a, int b){
        int depA = depth[a];
        int depB = depth[b];

        // a가 더 크도록 만들어놓음
        if (depA < depB) {
            int tmp = depA;
            depA = depB;
            depB = tmp;

            tmp = a;
            a = b;
            b = tmp;
        }

        // 깊이 같게 맞추기
        for (int j = 17; j >=0; j--){
            if (depA == depB) break;

            if (depA - (int)Math.pow(2, j) >= depB){
                // 깊이 조절
                depA -= (int)Math.pow(2, j);
                // 2^j번째로 올라옴
                a = parent[j][a];
            }
        }

        answer = a;

        // 조상 찾기
        if (a != b){
            for (int j = 17; j >= 0; j--){
                if (parent[j][a] != parent[j][b]){
                    a = parent[j][a];
                    b = parent[j][b];
                }
                answer = parent[j][a];
            }
        }
    }
}
