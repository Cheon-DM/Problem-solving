package sds.DAY02.P1806;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int N, S;
    static int[] inputs;

    public static void main(String[] args) throws IOException {
        //System.setIn(new FileInputStream("src/sds/DAY02/P1806/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        S = Integer.parseInt(st.nextToken());
        inputs = new int[N+1];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            inputs[i] = Integer.parseInt(st.nextToken());
        }

        int left = 0, right = 0, sum = 0, length = N+1;

        while (left < N) {
            if (sum >= S) { // 합이 S 이상인 경우
                length = Math.min(length, right-left);
                sum -= inputs[left++];
            }

            else if (right != N){ // 합이 S 미만이고 아직 right이 N에 도달하지 않은 경우
                sum += inputs[right++];
            }

            else { // right이 N에 도달한 경우
                sum -= inputs[left++];
            }
        }

        if (length == N+1){
            System.out.println(0);
        } else {
            System.out.println(length);
        }
    }
}
