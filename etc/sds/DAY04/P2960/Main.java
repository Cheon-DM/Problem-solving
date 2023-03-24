package sds.DAY04.P2960;

import java.io.*;
import java.util.StringTokenizer;

public class Main {

    static int N, K;
    static boolean[] prime; // false: 소수, true: 소수X

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        prime = new boolean[N+1];
        prime[0] = true;
        prime[1] = true;
        int ans = 0;
        int cnt = 0;
        boolean flag = false;
        for (int i = 2; i <= N; i++) {
            if (!prime[i]){ // i = 소수
                cnt++;

                if (cnt == K){
                    ans = i;
                    break;
                }

                for (int j = 2*i; j <= N; j += i) {
                    if (!prime[j]){ // 지우지 않은 것 중
                        // i의 배수는 소수 X
                        prime[j] = true;
                        cnt++;

                        if (cnt == K){
                            ans = j;
                            flag = true;
                            break;
                        }
                    }
                }

                if (flag) break;
            }
        }


        bw.write(ans + "\n");
        bw.flush();
        bw.close();
        br.close();
    }
}
