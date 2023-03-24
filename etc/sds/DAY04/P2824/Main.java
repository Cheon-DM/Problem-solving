package sds.DAY04.P2824;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static final int MAX = 1000000000;
    static int N, M;
    static int[] A, B;

    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("src/sds/DAY04/P2824/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        A = new int[N];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }

        M = Integer.parseInt(br.readLine());
        B = new int[M];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < M; i++) {
            B[i] = Integer.parseInt(st.nextToken());
        }

        long ans = 1;
        boolean flag = false;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int gcd = GCD(A[i], B[j]);
                ans *= gcd;

                if (ans >= MAX) {
                    flag = true;
                }

                ans %= MAX;
                A[i] /= gcd;
                B[j] /= gcd;
            }
        }

        String str = String.valueOf(ans);
        StringBuilder sb = new StringBuilder();
        if (flag){
            if (str.length() < 9){
                while (sb.length() + str.length() < 9){
                    sb.append("0");
                }
            }
        }

        sb.append(ans);
        System.out.println(sb.toString());

    }

    static int GCD(int a, int b){
        while (b != 0){
            int r = a % b;
            a = b;
            b = r;
        }

        return a;
    }
}
