package sds.DAY05.P1256;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * N개의 a와 M개의 z로 만들수 있는 문자열 경우의 수
 * -> N = 3, M = 2인 경우, z를 고르는 경우의 수 구하기
 * -> N+M개를 M칸 짜리 바구니에 담는 방법
 * nCk = n-1Ck + n-1Ck-1
 */

public class Main {

    static int seq;
    static final int MAX = 1000000000;
    static int N, M, K;
    static int[][] pascal;
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("src/sds/DAY05/P1256/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        pascal = new int[N+M+1][N+M+1];
        comb();
        findK(K, N, M);
        if (pascal[N+M][M] < K){
            System.out.println(-1);
        } else {
            System.out.println(sb.toString());
        }
    }

    static void comb(){ // 이중 for문
        pascal[0][0] = 1;
        for (int i = 1; i <= N+M; i++){
            pascal[i][0] = 1;

            for (int j = 1; j <= N+M; j++){
                pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
                if (pascal[i][j] > MAX) pascal[i][j] = MAX;
            }

            if (i <= M) pascal[i][i] = 1;
        }
    }

    static int[][] dp = new int[201][201];

    static int combRecursion(int n, int r){ // 재귀함수 이용
        if (n == r || r == 0){
            return 1;
        } else if (dp[n][r] != 0) {
            return dp[n][r];
        } else {
            return dp[n][r] = combRecursion(n-1, r-1) + combRecursion(n-1, r);
        }
    }

    static void findK(int res, int a, int z){
        int total = a + z;

        if (a == 0) {
            for (int i = 0; i < z; i++){
                sb.append("z");
            }
            return;
        }

        if (z == 0){
            for (int i = 0; i < a; i++){
                sb.append("a");
            }
            return;
        }

        int aNum = pascal[total - 1][a-1];

        if (aNum < res){ // 남은 갯수 더 많은 (z 추가)
            sb.append("z");
            findK(res - aNum, a, z-1);
        } else { // 적음 (a 추가)
            sb.append("a");
            findK(res, a-1, z);
        }
    }

    static void findStringIdx(int a, int z, String str){
        // str이 1글자인 경우
        if (str.length() == 1){
            if (str.charAt(0) == 'a'){

            } else {

            }
        }

        // str이 2글자 이상인 경우
        sb = new StringBuilder();
        sb.append(str);
        sb.deleteCharAt(0);

        int aEndIdx = pascal[a + z - 1][a - 1];
        if (str.charAt(0) == 'a'){ // 앞 글자가 a인 경우
            seq -= aEndIdx;
            findStringIdx(a-1, z, sb.toString());
        } else { // 앞 글자가 z인 경우
            findStringIdx(a, z-1, sb.toString());
        }
    }
}
