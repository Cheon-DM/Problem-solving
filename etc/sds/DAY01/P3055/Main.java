package sds.DAY01.P3055;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Pos {
    int x, y;

    char type; // 고슴도치 : H, 동굴 : D, 물 : W, 미정 : A

    public Pos(int x, int y, char type) {
        this.x = x;
        this.y = y;
        this.type = type;
    }

    @Override
    public int hashCode() {
        return super.hashCode();
    }

    @Override
    public boolean equals(Object obj) {
        return this.x == ((Pos)obj).x && this.y == ((Pos)obj).y;
    }
}

public class Main {

    static int R, C;
    static Queue<Pos> queue;
    static Pos hedgehog, cave;
    static String[][] map;
    static int[][] dp;
    static boolean[][] visited;
    static final int[] dx = {-1, 1, 0, 0};
    static final int[] dy = {0, 0, -1, 1};
    static final String NOT_MOVE = "KAKTUS";

    public static void main(String[] args) throws FileNotFoundException {
        System.setIn(new FileInputStream("src/sds/DAY01/P3055/input.txt"));
        Scanner sc = new Scanner(System.in);

        R = sc.nextInt();
        C = sc.nextInt();

        map = new String[R][C];
        dp = new int[R][C];
        visited = new boolean[R][C];
        queue = new LinkedList<>();

        for (int i = 0; i < R; i++){
            map[i] = sc.next().split("");
            for (int j = 0; j < C; j++){

                if (map[i][j].equals("S")) {
                    hedgehog = new Pos(i, j, 'H');
                    visited[i][j] = true;
                }
                if (map[i][j].equals("D")){
                    cave = new Pos(i, j, 'D');
                }
                if (map[i][j].equals("*")){
                    // 물을 먼저 넣어줌
                    queue.add(new Pos(i, j, 'W'));
                }
            }
        }

        bfs(hedgehog);
    }

    static void bfs(Pos start){
        // 고슴도치를 넣어줌
        queue.add(start);
        visited[start.x][start.y] = true;

        while (!queue.isEmpty()){

            // 큐에서 꺼냄
            Pos cur = queue.poll();

            // 목적지인가?
            if (cur.equals(cave)){
                System.out.println(dp[cur.x][cur.y]);
                return;
            }

            // 연결된 곳 순회
            for (int i = 0; i < 4; i++){
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];

                // 갈 수 없음 (경계값, 돌)
                if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                if (map[nx][ny].equals("X")) continue;

                // 갈 수 있는가?
                if (!visited[nx][ny]){
                    // 갈 수 있는가? - 물
                    if (cur.type == 'W'){
                        // 물은 동굴 못감
                        if(map[nx][ny].equals("D")) continue;

                        // 체크인
                        map[nx][ny] = "*";
                        dp[nx][ny] = dp[cur.x][cur.y];
                        visited[nx][ny] = true;
                    }

                    // 갈 수 있는가? - 고슴도치
                    else if (cur.type == 'H'){
                        // 고슴도치는 물에 못감
                        if (map[nx][ny].equals("*")) continue;

                        // 체크인
                        dp[nx][ny] = dp[cur.x][cur.y] + 1;
                        visited[nx][ny] = true;
                    }

                    // 큐에 넣음
                    queue.add(new Pos(nx, ny, cur.type));
                }
            }
        }

        System.out.println(NOT_MOVE);
    }
}
