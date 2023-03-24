package sds.DAY03.P2243;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int n, S;
    static int[] tree;

    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("src/sds/DAY03/P2243/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        n = Integer.parseInt(br.readLine());
        S = 1;
        while (S < 1000000){
            S *= 2;
        }
        tree = new int[S * 2];

        for (int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            int A = Integer.parseInt(st.nextToken());

            if (A == 1){ // 사탕을 꺼낼 때 (find + update)
                int B = Integer.parseInt(st.nextToken());
                int target = query(1, S, 1, B);
                update(1, S, 1, target, -1);
                System.out.println(target);
            }

            else if (A == 2){ // 사탕을 넣어줄 때 (update)
                int B = Integer.parseInt(st.nextToken());
                int C = Integer.parseInt(st.nextToken());
                update(1, S, 1, B, C);
            }
        }
    }

    static void update(int left, int right, int node, int target, int diff) {
        // 연관 없음
        if (right < target || target < left) {

        }

        // 연관 있음
        else {
            // 현재 값 갱신
            tree[node] += diff;

            // 내부노드인 경우
            if (left != right) {
                int mid = (left + right) / 2;
                update(left, mid, node*2, target, diff);
                update(mid+1, right, node*2+1, target, diff);
            }
        }
    }

    static int find(int left, int right, int node, int target){
        if (left == right) return left;

        int mid = (left + right) / 2;

        // left
        if (tree[node * 2] >= target) {
            return find (left, mid, node * 2, target);
        } else { // right
            return find(mid + 1, right, node * 2 + 1, target - tree[node * 2]);
        }
    }

    static int query (int left, int right, int node, int target){
        // 연관 없음
        if (target < 1 || tree[node] < target){
            return 0;
        }

        // 판단 가능
        if (left == right) return left;

        // 판단 불가
        int mid = (left + right) / 2;
        int leftValue = query(left, mid, node*2, target);
        int rightValue = query(mid+1, right, node*2+1, target-tree[node*2]);
        return leftValue + rightValue;
    }
}

