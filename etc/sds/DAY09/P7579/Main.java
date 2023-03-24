package sds.DAY09.P7579;

import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

class App implements Comparable<App>{
    int memory;
    int cost;

    public App(int memory, int cost) {
        this.memory = memory;
        this.cost = cost;
    }

    public void setCost(int cost) {
        this.cost = cost;
    }

    @Override
    public int compareTo(App o) {
        int comp1 = cost - o.cost;
        if (comp1 == 0) return o.memory - memory;
        return comp1;
    }
}

public class Main {

    static int N, M;
    static App[] apps;
    static int[][] dp;

    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("src/sds/DAY09/P7579/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        apps = new App[N];

        // 메모리의 크기가 매우 크기 때문에 비용을 기준으로 해줘여함.
        dp = new int[N+1][N*100+1]; // N개의 앱, 각각의 최대 비용 = 100이므로 N*100 비용까지 들 수 있음.

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            int m = Integer.parseInt(st.nextToken());
            apps[i] = new App(m, 0);
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            int c = Integer.parseInt(st.nextToken());
            apps[i].setCost(c);
        }

        Arrays.sort(apps);

        int ans = Integer.MAX_VALUE;
        // dp[x][y] : x번째까지의 앱을 사용할 때, y비용으로 확보 가능한 메모리 바이트 수
        for (int i = 0; i < N; i++) {
            int memory = apps[i].memory;
            int cost = apps[i].cost;

            for (int j = 0; j <= N*100; j++) {
                if (i == 0) {
                    if (j >= cost){ // 앱 1개인 경우 저장 = index로 인해 else->if 부분을 직접 넣어주는 부분
                        dp[i][j] = memory;
                    }
                }

                else {
                    if (j >= cost){ // 현재 비용으로 가능
                        dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - cost] + memory);
                    }
                    else { // 현재 비용으로 불가능 -> 이전 dp 가져오기
                        dp[i][j] = dp[i-1][j];
                    }
                }

                if (dp[i][j] >= M) {
                    ans = Math.min(ans, j);
                }
            }
        }

        bw.write(ans + "\n");
        bw.flush();
        bw.close();
        br.close();
    }
}
