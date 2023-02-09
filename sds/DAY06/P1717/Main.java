package sds.DAY06.P1717;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int N, M, commend, A, B;
    static int[] parent;

    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("src/sds/DAY06/P1717/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        parent = new int[N+1];
        init(N);

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            commend = Integer.parseInt(st.nextToken());
            A = Integer.parseInt(st.nextToken());
            B = Integer.parseInt(st.nextToken());

            if (commend == 0){
                union(A, B);
            }

            if (commend == 1){
                int aRoot = find(A);
                int bRoot = find(B);
                if (aRoot == bRoot) {
                    System.out.println("YES");
                } else {
                    System.out.println("NO");
                }
            }
        }
    }

    static void init(int n){
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    static void union(int a, int b){
        int aRoot = find(a);
        int bRoot = find(b);
        parent[aRoot] = bRoot;
    }

    static int find(int a){
        if (parent[a] == a) return a;
        else return parent[a] = find(parent[a]);
    }
}
