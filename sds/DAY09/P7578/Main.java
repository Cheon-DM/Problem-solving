package sds.DAY09.P7578;

import java.io.*;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int[] A, B;
    static Map<Integer, Integer> machineMap;
    static int S;
    static long[] tree;

    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("src/sds/DAY09/P7578/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        N = Integer.parseInt(br.readLine());

        A = new int[N+1];
        B = new int[N+1];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }

        machineMap = new HashMap<>();
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            B[i] = Integer.parseInt(st.nextToken());
            // B열에 위치한 기계 식별번호(key)는 인덱스(value) 위치에 있음
            machineMap.put(B[i], i);
        }

        S = 1;
        while (S < N){
            S *= 2;
        }

        long ans = 0;
        tree = new long[2*S];
        for (int i = 1; i <= N; i++) {
            // A열에 위치한 기계 식별번호(A[i])와 같은 B열의 기계 인덱스 번호
            int indexB = machineMap.get(A[i]);

            // 이미 연결된 케이블과 교차하는 케이블 개수 구하기
            ans += query(1, S, 1, indexB+1, N);

            // 해당 인덱스 번호 방문
            update(1, S, 1, indexB, 1);
        }

        bw.write(ans + "\n");
        bw.flush();
        bw.close();
        br.close();
    }

    static long query(int left, int right, int node, int queryLeft, int queryRight){
        // 연관 없음
        if (queryRight < left || right < queryLeft) return 0;

        // 판단 가능
        if (queryLeft <= left && right <= queryRight){
            return tree[node];
        }

        // 판단 불가
        int mid = (left + right) / 2;
        long leftValue = query(left, mid, node*2, queryLeft, queryRight);
        long rightValue = query(mid+1, right, node*2+1, queryLeft, queryRight);
        return leftValue + rightValue;
    }

    static void update(int left, int right, int node, int target, int diff){
        // 연관 없음
        if (target < left || right < target) return;

        // 연관 있음
        // 현재 노드에 추가
        tree[node] += diff;

        if (left != right){
            int mid = (left + right) / 2;
            update(left, mid, node*2, target, diff);
            update(mid+1, right, node*2+1, target, diff);
        }
    }
}
