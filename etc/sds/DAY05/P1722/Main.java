package sds.DAY05.P1722;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int N, k;
    static long[] factorial;
    static boolean[] visited;
    static int[] inputs;
    static long answerIdx = 1;

    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("src/sds/DAY05/P1722/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        factorial = new long[N+1];
        setFactorial();

        StringTokenizer st = new StringTokenizer(br.readLine());
        k = Integer.parseInt(st.nextToken());

        visited = new boolean[N+1];

        if (k == 1){
            long target = Long.parseLong(st.nextToken());
            StringBuilder sb = new StringBuilder();

            for (int i = 0; i < N; i++) { // 자리 수
                for (int j = 1; j <= N; j++) { // 1, 2, 3, 4, ... 숫자를 의미
                    if (!visited[j]) { // 아직 방문하지 않음.
                        // target이 경계보다 큰 경우
                        if (target > factorial[N - i -1]){
                            // 밑으로 탐색하러 감.
                            target -= factorial[N - i - 1];
                        }

                        // target이 경계보다 작은 경우
                        else {
                            sb.append(j);
                            sb.append(" ");
                            visited[j] = true;
                            break;
                        }
                    }

                }
            }

            System.out.println(sb.toString());
        } else if (k == 2){
            inputs = new int[N];
            for (int i = 0; i < N; i++) {
                inputs[i] = Integer.parseInt(st.nextToken());
            }

            for (int i = 0; i < N; i++){
                for (int j = 1; j < inputs[i]; j++){
                    if (!visited[j]){
                        // 이전 단계까지 옮김
                        answerIdx += factorial[N-i-1];
                    }
                }
                visited[inputs[i]] = true;
            }

            System.out.println(answerIdx);
        }
    }

    static void setFactorial(){
        factorial[0] = 1;
        factorial[1] = 1;
        for (int i = 2; i <= N; i++) {
            factorial[i] = factorial[i-1] * i;
        }
    }
}
