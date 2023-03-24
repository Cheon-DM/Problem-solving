package sds.DAY01.P1103;

import java.io.*;
import java.util.StringTokenizer;

public class Main {

    static int N, M, answer;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    static String[] board;
    static boolean[][] visited;
    static int[][] dp;
    static boolean flag;

    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("src/sds/DAY01/P1103/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        board = new String[N];
        visited = new boolean[N][M];
        dp = new int[N][M];

        for (int i = 0; i < N; i++){
            String str = br.readLine();
            board[i] = str;
        }

        answer = 0;
        dfs(0, 0, 1);
        if (flag){
            System.out.println(-1);
        } else {
            System.out.println(answer);
        }
    }

    private static void dfs(int x, int y, int count){

        // 최대값 저장
        if (answer < count){
            answer = count;
        }

        // 해당 루트 count 저장
        dp[x][y] = count;

        // 연결된 곳 순회
        for (int i = 0; i < 4; i++){
            int nx = x + charToInt(board[x].charAt(y)) * dx[i];
            int ny = y + charToInt(board[x].charAt(y)) * dy[i];

            // 갈 수 있는가? (X)
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (board[nx].charAt(ny) == 'H') continue;

            // 이미 방문해서 loop 가능
           if (visited[nx][ny]){
                flag = true;
                return;
            }

           // 방문 지점이 예전 경우가 더 많음
            if (dp[nx][ny] > count) continue;

            // 체크인
            visited[nx][ny] = true;
            // 간다
            dfs(nx, ny, count+1);
            // 체크아웃
            visited[nx][ny] = false;
        }
    }

    static int charToInt(char a){
        return a - '0';
    }
}
