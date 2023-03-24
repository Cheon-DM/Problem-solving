package sds.DAY03.P2042;

import java.io.*;
import java.util.StringTokenizer;

public class Main {

    static int N, M, K;
    static int S;
    static long[] inputs;
    static long[] tree;

    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("src/sds/DAY03/P2042/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        inputs = new long[N];
        for (int i = 0; i < N; i++){
            inputs[i] = Long.parseLong(br.readLine());
        }

        init();

        for (int i = 0; i < M+K; i++){
            st = new StringTokenizer(br.readLine());
            int commend = Integer.parseInt(st.nextToken());

            if (commend == 1){ // update
                int target = Integer.parseInt(st.nextToken());
                long value = Long.parseLong((st.nextToken()));
                update(1, S, 1, target, value-tree[S + target-1]);
            }

            else if (commend == 2){ // sum
                int queryLeft = Integer.parseInt(st.nextToken());
                int queryRight = Integer.parseInt(st.nextToken());
                System.out.println(query(1, S, 1, queryLeft, queryRight));
            }
        }
    }

    static void init(){
        // S 구하기
        S = 1;
        while (S < N){
            S *= 2;
        }

        // tree 크기 설정
        tree = new long[S*2];

        // 리프 노드 값 추가
        for (int i = 0; i < N; i++){
            tree[S+i] = inputs[i];
        }

        // 내부 노드 값 추가
        for (int i = S-1; i > 0; i--){
            tree[i] = tree[i*2] + tree[i*2+1];
        }
    }

    static void update(int left, int right, int node, int target, long diff){
        // 연관 X
        if (target < left || right < target) {
        }

        // 연관 O
        else {
            tree[node] += diff;

            // 내부 노드인 경우 리프노드까지 이동 필요
            if (left != right){
                int mid = (left + right) / 2;
                update(left, mid, node*2, target, diff);
                update(mid+1, right, node*2+1, target, diff);
            }
        }
    }

    static long query(int left, int right, int node, int queryLeft, int queryRight){
        // 연관 없음
        if (right < queryLeft || queryRight < left){
            return 0;
        }

        // 판단 가능
        else if ( queryLeft <= left && right <= queryRight){
            return tree[node];
        }

        // 판단 불가
        else {
            int mid = (left + right) / 2;
            long leftValue = query(left, mid, node * 2, queryLeft, queryRight);
            long rightValue = query(mid+1, right, node * 2 + 1, queryLeft, queryRight);

            return leftValue + rightValue;
        }
    }
}
