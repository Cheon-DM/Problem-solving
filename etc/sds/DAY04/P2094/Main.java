package sds.DAY04.P2094;

import java.io.*;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {

    static int N, M, S;
    static int[] tree;
    static int[] rainy, years;
    static Map<Integer, Integer> yearIndexMap = new HashMap<>();

    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("src/sds/DAY04/P2094/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());

        init();

        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            years[i] = Integer.parseInt(st.nextToken());
            rainy[i] = Integer.parseInt(st.nextToken());

            // key : 연도, value : 인덱스 접근 값
            yearIndexMap.put(years[i], i);
            update(1, S, 1, i, rainy[i]);
        }

        M = Integer.parseInt(br.readLine());

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int Xyear, Yyear;
            Yyear = Integer.parseInt(st.nextToken());
            Xyear = Integer.parseInt(st.nextToken());

            Integer xIndex = yearIndexMap.get(Xyear);
            Integer yIndex = yearIndexMap.get(Yyear);

            // 두 연도 강수량을 다 모름
            if (xIndex == null && yIndex == null){
                bw.write("maybe\n");
            } else {
                if (xIndex == null){

                } else if (yIndex == null){

                } else { // 두 연도 강수량을 알음
                    if (xIndex > yIndex) {
                        bw.write("false\n");
                    } else {

                    }
                }
            }
        }

        System.out.println();
    }

    // “X년도에는 Y년도 이후 가장 많은 비가 내렸다” Y -> X 순서
    static boolean check(int yIndex, int xIndex, int flag){
        // 사이 연도의 강수량 비교하기
        xIndex--;
        yIndex++;

        if (yIndex > xIndex) return true;

        int rain = query(1, S, 1, yIndex, xIndex);

        return false;
    }

    static void init(){
        S = 1;
        while (S < N) {
            S *= 2;
        }

        tree = new int[2*S];
        rainy = new int[N+1];
        years = new int[N+1];
    }

    static int query(int left, int right, int node, int qLeft, int qRight) {
        // 연관 없음
        if (right < qLeft || qRight < left) return 0;

        // 판단 가능
        if (qLeft <= left && right <= qRight) return tree[node];

        // 판단 불가
        int mid = (left + right) / 2;
        return query(left, mid, node * 2, qLeft, qRight) + query(mid + 1, right, node * 2 + 1, qLeft, qRight);
    }

    static void update(int left, int right, int node, int target, int rain) {
        // 연관 없음
        //if (target < left || right < target) return;

        // 연관 있음
        if (left == right) {
            tree[node] = rain;
            return;
        }

        int mid = (left + right) / 2;
        if (target <= mid){
            update(left, mid, node * 2, target, rain);
        } else {
            update(mid + 1, right, node * 2 + 1, target, rain);
        }
        // 부모에 최대값 저장하기
        tree[node] = Math.max(tree[node * 2], tree[node * 2 + 1]);

    }
}
