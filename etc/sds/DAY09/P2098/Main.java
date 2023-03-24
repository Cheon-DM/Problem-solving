package sds.DAY09.P2098;

import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int[][] W;
    static int[][] dp; // dp[cur][visitmap] cur(현재 도시)에서 visitmap만큼 방문했을 때의 최단 거리
    static int fullVisit;
    static final int INF = Integer.MAX_VALUE / 2;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        // N(도시의 수) 입력
        N = Integer.parseInt(br.readLine());

        // W(이동 비용) 입력
        W = new int[N][N];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                W[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        // init
        dp = new int[N][65537]; // 2의 16승
        for (int i = 0; i < N; i++) {
            Arrays.fill(dp[i], INF);
        }
        fullVisit = (1 << N) - 1;

        // 0번째 도시부터 방문할 예정이므로 cur = 0, bit = 00000001 = 1
        int ans = TSP(0, 1);
        if (ans == INF){
            bw.write("-1\n");
        } else {
            bw.write(ans + "\n");
        }

        bw.flush();
        bw.close();
        br.close();
    }

    static int TSP(int cur, int bitmask){

        // 모든 도시 방문
        if (bitmask == fullVisit){
            // 시작점을 갈 수 있는가
            if (W[cur][0] > 0){
                return W[cur][0];
            } else {
                // 갈 수 없으면 방문 불가 표시 (INF 표시)
                return INF/2;
            }
        }

        // Todo: 이부분이 왜 필요한지 생각해보기.
        if (dp[cur][bitmask] != INF) {
            return dp[cur][bitmask];
        }

        // 0번 노드에서 시작해서 각 도시 방문하기
        for (int next = 1; next < N; next++) {
            // 도달 가능한가?
            if (W[cur][next] > 0) {

                /**
                 * (1 << next) : next를 2진수로 변경
                 * 변경된 next 이진수와 bitmask와 and(&) 계산
                 * -> 방문했으면 1이 나오고, 방문하지 않았으면 0이 나옴
                 */
                // 현재로 되돌아가지 않고, 방문하지 않은 도시인 경우
                if (next != cur && ((1 << next) & bitmask) == 0) {
                    // bitmask에 다음 방문을 체크(or 연산을 통해)
                    int nCost = TSP(next, (bitmask | (1 << next))) + W[cur][next];

                    // 최단 비용인 경우 갱신
                    if (dp[cur][bitmask] > nCost) {
                        dp[cur][bitmask] = nCost;
                    }
                }
            }
        }

        return dp[cur][bitmask];
    }
}
