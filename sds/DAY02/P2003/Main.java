package sds.DAY02.P2003;
/**
 * two pointer (sliding window)
 */

import java.io.*;
import java.util.StringTokenizer;

public class Main {

    static int N, M;
    static int left, right, cnt, sum;
    static int[] inputs;

    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("src/sds/DAY02/P2003/input.txt"));
//        Scanner sc = new Scanner(System.in);
        // 성능 향상 스캐너
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // bf.readline() : 한 줄 모두 읽기
        StringTokenizer st = new StringTokenizer(br.readLine()); // 띄어쓰기로 토큰 나눔
        N = Integer.parseInt(st.nextToken()); // 다음 값을 넘겨줌
        M = Integer.parseInt(st.nextToken());

        inputs = new int[N];
        st = new StringTokenizer(br.readLine()); // 다음 줄 읽기
        for (int i = 0 ; i < N; i++){
            inputs[i] = Integer.parseInt(st.nextToken());
        }

        left = right = cnt = sum = 0;

        while (left < N){
            if (sum == M){
                cnt++;
            }

            if (sum >= M || right == N) {
                sum -= inputs[left];
                left++;
            }

            else {
                sum += inputs[right];
                right++;
            }
        }

        System.out.println(cnt);
    }
}
