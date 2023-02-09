package sds.DAY01.P1039;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static int N, K;
    static int len;
    static boolean[][] checked;
    static Queue<int[]> q = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("src/sds/DAY01/P1039/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        int tmp = N;
        while (tmp != 0){
            len++;
            tmp /= 10;
        }

        if (len <= 1) {
            System.out.println(-1);
        }
        else {
            checked = new boolean[1000001][K+1];
            // 0 : 숫자 N, 1: ~번 바꿈
            q.add(new int[]{N, 0});
            checked[N][0] = true;

            int result = -1;

            while (!q.isEmpty()) {
                int[] cur = q.poll();

                if (cur[1] == K){
                    if (result < cur[0]){
                        result = cur[0];
                    }
                    continue;
                }

                for (int i = 0; i < len - 1; i++) {
                    for (int j = i+1; j < len; j++) {
                        int next = swap(cur[0], i, j);

                        // 갈 수 있는가?
                        if (next != -1 && !checked[next][cur[1]+1]){
                            checked[next][cur[1]+1] = true;
                            q.add(new int[]{next, cur[1] + 1});
                        }
                    }
                }
            }

            System.out.println(result);
        }
    }

    // x숫자에서 i번째 <-> j번째 swap
    static int swap(int x, int i, int j){
        StringBuilder sb = new StringBuilder();
        char[] input = sb.append(x).toString().toCharArray();

        // 첫 번째랑 교환할 차례인데 바꿀 숫자가 0인 경우
        if (i == 0 && input[j] == '0') {
            return -1;
        }

        char tmp = input[i];
        input[i] = input[j];
        input[j] = tmp;

        int result = 0;
        for (char c : input) {
            result *= 10;
            result += c - '0';
        }

        return result;
    }
}
