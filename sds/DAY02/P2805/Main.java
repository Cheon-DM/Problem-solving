package sds.DAY02.P2805;

/**
 * parametric search
 * O(logN)
 */

import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int N, M;
    static long answer = Long.MAX_VALUE;
    static int[] trees;

    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("src/sds/DAY02/P2805/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        trees = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++){
            trees[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(trees);

        long left = 0, right = trees[N-1];

        while (left <= right){
            long mid = (left + right) / 2;
            long sum = calc(mid);

            if (sum >= M){ // 원하는 나무 길이 이상 되었을 때
                left = mid + 1;
                answer = mid;
            }

            else { // 원하는 나무 길이가 안나올 때
                right = mid - 1;
            }
        }

        System.out.println(answer);
    }

    private static long calc(long mid) {
        long sum = 0;

        for (int i = 0; i < N; i++){
            if (trees[i] - mid > 0) {// 나무 잘라서 모두 더하기
                sum += trees[i] - mid;
            }
        }
        return sum;
    }
}
