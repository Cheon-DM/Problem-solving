package sds.DAY06.P3176;

/**
 * 주어진 데이터 양이 많으므로 플로이드-워셜 사용 불가
 */

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

class Node {
    int next;
    int len;

    public Node(int next, int len) {
        this.next = next;
        this.len = len;
    }
}

public class Main {

    static int N, K, A, B, C, D, E;
    static List<Node>[] tree;
    static int[] depth;
    static int[][] parent;
    static int[][] minDist;
    static int[][] maxDist;

    static int minAns, maxAns;

    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("src/sds/DAY06/P3176/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());

        //init
        depth = new int[N+1];
        parent = new int[18][N+1]; // 2^17까지(10만)
        minDist = new int[18][N+1];// 길이 저장
        maxDist = new int[18][N+1];

        tree = new List[N+1];
        for (int i = 1; i <= N; i++) {
            tree[i] = new ArrayList<>();
        }

        for (int i = 0; i < N - 1; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            A = Integer.parseInt(st.nextToken());
            B = Integer.parseInt(st.nextToken());
            C = Integer.parseInt(st.nextToken());

            tree[A].add(new Node(B, C));
            tree[B].add(new Node(A, C));
        }

        setDepth(1, 1);
        setParent();

        K = Integer.parseInt(br.readLine());
        for (int i = 0; i < K; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            D = Integer.parseInt(st.nextToken());
            E = Integer.parseInt(st.nextToken());
            LCA(D, E);

            System.out.println(minAns + " " + maxAns);
        }
    }

    static void setDepth(int cur, int dep){
        // depth 계산 체크
        depth[cur] = dep;

        for (int i = 0; i < tree[cur].size(); i++) {
            // 현재 노드와 연결된 다음 노드
            Node next = tree[cur].get(i);
            int dest = next.next;
            int len = next.len;

            // depth를 계산했는가?
            if (depth[dest] == 0){
                setDepth(dest, dep+1);

                // dest의 직계 조상 = cur
                parent[0][dest] = cur;
                minDist[0][dest] = len;
                maxDist[0][dest] = len;

            }
        }
    }

    static void setParent(){
        for (int i = 1; i <= 17; i++){
            for (int j = 1; j <= N; j++) {
                parent[i][j] = parent[i-1][parent[i-1][j]];

                minDist[i][j] = Math.min(minDist[i - 1][j], minDist[i - 1][parent[i - 1][j]]);
                maxDist[i][j] = Math.max(maxDist[i - 1][j], maxDist[i - 1][parent[i - 1][j]]);
            }
        }
    }

    static void LCA(int d, int e){
        minAns = 1000000000;
        maxAns = -1;

        // 앞 쪽 depth > 뒤 쪽 depth 순서 맞추기
        if (depth[d] < depth[e]){
            int tmp = d;
            d = e;
            e = tmp;
        }

        int depthD = depth[d];
        int depthE = depth[e];

        // 높이 맞추기
        if (depthD != depthE){
            for (int i = 17; i >= 0; i--){
                if (depthD - (int)Math.pow(2, i) >= depthE){
                    depthD -= (int)Math.pow(2, i);

                    minAns = Math.min(minAns, minDist[i][d]);
                    maxAns = Math.max(maxAns, maxDist[i][d]);
                    d = parent[i][d];
                }
            }
        }

        if (d == e){
            return;
        }

        // 조상 찾기
        for (int j = 17; j >= 0; j--) {
            if (parent[j][d] != parent[j][e]){
                minAns = Math.min(minAns, Math.min(minDist[j][d], minDist[j][e]));
                maxAns = Math.max(maxAns, Math.max(maxDist[j][d], maxDist[j][e]));

                d = parent[j][d];
                e = parent[j][e];
            }
        }

        minAns = Math.min(minAns, Math.min(minDist[0][d], minDist[0][e]));
        maxAns = Math.max(maxAns, Math.max(maxDist[0][d], maxDist[0][e]));
    }
}
