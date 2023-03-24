package sds.DAY06.P1922;

import java.io.*;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class Node implements Comparable<Node>{
    int start;
    int end;
    int cost;

    public Node(int start, int end, int cost) {
        this.start = start;
        this.end = end;
        this.cost = cost;
    }

    @Override
    public int compareTo(Node n) {
        int comp1 = cost - n.cost;
        if (comp1 == 0){
            return start - n.start;
        } else return comp1;
    }
}

public class Main {

    static int N, M;
    static int a, b, c;
    static int[] arr;
    static PriorityQueue<Node> pq;

    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("src/sds/DAY06/P1922/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());
        arr = new int[N+1];
        for (int i = 0; i <= N; i++){
            arr[i] = i;
        }
        pq = new PriorityQueue<>();

        for (int i = 0 ; i < M; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());

            pq.add(new Node(a, b, c));
        }

        int E = 0;
        int sum = 0;
        while (E != N-1){
            Node cur = pq.poll();
            int a = cur.start;
            int b = cur.end;

            boolean flag = union(a, b);

            if (flag) {
                sum += cur.cost;
                E++;
            }
        }

        System.out.println(sum);
    }

    static boolean union(int a, int b){
        int aRoot = find(a);
        int bRoot = find(b);

        if (aRoot == bRoot) return false;

        arr[aRoot] = bRoot;
        return true;
    }

    static int find(int a){
        if (arr[a] == a) return a;
        else return arr[a] = find(arr[a]);
    }
}
