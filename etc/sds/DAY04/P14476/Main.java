package sds.DAY04.P14476;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * Left to Right 배열 만듦 : 왼쪽부터 쌓은 누적합 배열 (1 gcd , 1~2 gcd , 1~3 gcd, ...)
 * Right to Left 배열 만듦 : 오른쪽부터 쌓은 누적합 배열 (1~4 gcd, 2~4 gcd, 3~4 gcd, 4 gcd)
 * ex) 3번 골랐을 때 : 1-2 + 4
 */

public class Main {

    static int N;
    static int[] inputs;
    static int[] LtR, RtL;

    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("src/sds/DAY04/P14476/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        inputs = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++){
            inputs[i] = Integer.parseInt(st.nextToken());
        }

        // LtR
        LtR = new int[N];
        LtR[0] = inputs[0];
        for (int i = 1; i < N; i++){
            LtR[i] = gcd(LtR[i-1], inputs[i]);
        }

        // RtL
        RtL = new int[N];
        RtL[N-1] = inputs[N-1];
        for (int i = N-2; i >= 0; i--){
            RtL[i] = gcd(RtL[i+1], inputs[i]);
        }

        int K = 0;
        int sum = -1;
        for (int i = 0; i < N; i++){
            int result;
            if (i == 0){
                result = RtL[1];
            }
            else if (i == N-1){
                result = LtR[N-2];
            }
            else {
                result = gcd(LtR[i-1], RtL[i+1]);
            }

            if (check(inputs[i], result) && sum < result){
                sum = result;
                K = inputs[i];
            }
        }

        if (K != 0){
            System.out.println(sum + " " + K);
        } else {
            System.out.println(-1);
        }

    }

    static int gcd(int a, int b){
        // gcd(a, b) == gcd(b, a % b), a % b == 0일 때 return

        while (b != 0) {
            int r = a % b;
            a = b;
            b = r;
        }

        return a;
    }

    static boolean check(int K, int r){
        return K % r != 0;
    }
}
