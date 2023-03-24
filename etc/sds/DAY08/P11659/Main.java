package sds.DAY08.P11659;

import java.io.*;
import java.util.StringTokenizer;

public class Main {

    static int N, M, I, J;
    static int[] inputs;
    static int[] leftSum;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        // n, m 입력
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        // inputs 초기화
        inputs = new int[N+1];

        // inputs 입력
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            inputs[i] = Integer.parseInt(st.nextToken());
        }

        // 누적 합 초기화
        leftSum = new int[N+1];

        // 누적 합
        leftSum[1] = inputs[1];
        for (int i = 2; i <= N; i++) {
            leftSum[i] = leftSum[i-1] + inputs[i];
        }

        // i, j 입력 후 i~j까지 합 출력
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            I = Integer.parseInt(st.nextToken());
            J = Integer.parseInt(st.nextToken());

            int sum = leftSum[J] - leftSum[I-1];
            bw.write(sum + "\n");
        }

        bw.flush();
        bw.close();
        br.close();
    }
}
