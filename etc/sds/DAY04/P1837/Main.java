package sds.DAY04.P1837;

/**
 * 1. 소수 리스트 만들기
 * 2. 암호 나누기
 */

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int K;
    static String P;
    static boolean[] prime;

    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("src/sds/DAY04/P1837/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        P = st.nextToken();
        K = Integer.parseInt(st.nextToken());
        prime = new boolean[1000001];

        // 소수 구하기 (false : 소수)
        prime[0] = prime[1] = true;
        for (int i = 2; i <= 1000000; i++){
            if (!prime[i]){ // 소수라면
                for (int j = 2 * i; j <= 1000000; j+=i){
                    prime[j] = true;
                }
            }
        }

        // 나눗셈
        int answer = -1;
        for (int i = 2; i < K; i++){
            if (!prime[i] && divide(i)){
                answer = i;
                break;
            }
        }

        if (answer == -1){
            System.out.println("GOOD");
        } else {
            System.out.println("BAD " + answer);
        }
    }

    static boolean divide(int x){
        int n = 0;

        for (int i = 0; i < P.length(); i++){
            n = n * 10 + P.charAt(i) - '0';
            n %= x;
        }

        return n == 0;
    }
}
