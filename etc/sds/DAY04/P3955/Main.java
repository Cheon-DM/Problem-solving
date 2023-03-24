package sds.DAY04.P3955;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * Kx + 1 = CY (K명, 사탕 C개)
 * K(-x) + Cy = 1
 * 유클리드 호제법 돌리기
 * 0 < x [실제 계산할 때는 x < 0], 0 < y < 10^9
 */

public class Main {

    static int T, K, C;

    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("src/sds/DAY04/P3955/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        T = Integer.parseInt(br.readLine());
        for (int t = 0; t < T; t++){
            st = new StringTokenizer(br.readLine());
            K = Integer.parseInt(st.nextToken());
            C = Integer.parseInt(st.nextToken());

            long[] result = extEuclid(K, C);
            if (result[1] != 1) { // gcd가 1이 아닌 경우 = 해를 구할 수 없음
                System.out.println("IMPOSSIBLE");
            } else { // As + Bt = r, Ax + By = C 두 식에서 C와 r을 일치시켜서 x0, y0을 구함 -> 초기해
                // x0 = s * C/r, y0 = t * C/r
                // 해당 문제는 C, r == 1이므로 x0 = s, y0 = t
                long s0 = result[0];
                long t0 = result[1];

                // 일반해 공식
                // x = x0 + B/D*K
                // y = y0 - A/D*K

                // x < 0 --> x0 + B*K < 0
                // K < -x0 / B

                // 0 < y <= 1e9
                // 0 < y0 - A * K <= 1e9
                // -y0 / A < -K <= (1e9 -y0) / A
                // y0 - 1e9 / A <= K < y0 / A

                long kFromY = (long) (Math.ceil((double) t0 / (double) K) - 1);
                long kFromX = (long) (Math.ceil((double) -s0 / (double) C));
                long k = Math.min(kFromX, kFromY);
                long kLimitFromY = (long) (Math.floor((double) (t0 - 1e9) / (double) K));
                if (kLimitFromY <= K){ // 조건 만족
                    System.out.println(t0 - K * k);
                } else {
                    System.out.println("IMPOSSIBLE");
                }

                t0 = (t0 % K + K) % K;
                t0 = Math.max(t0, (K+C)/C);

                // 제한
                if (t0 <= 1e9){
                    System.out.println(t0);
                } else {
                    System.out.println("IMPOSSIBLE");
                }
            }
        }
    }

    static long[] extEuclid(long a, long b){
        long s0 = 1, t0 = 0;
        long s1 = 0, t1 = 1;

        while (b != 0){
            long q = a / b;
            long r = a % b;
            a = b;
            b = r;

            long s = s0 - q*s1;
            long t = t0 - q*t1;
            s0 = s1;
            s1 = s;
            t0 = t1;
            t1 = t;
        }

        // 구해햐 하는 것 t(사탕 봉지수), gcd
       return new long[] {s0, t0, a};
    }
}
