package sds.DAY01.P1103;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {

    static int N, M;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 0};
    static String[][] board;

    public static void main(String[] args) throws FileNotFoundException {
        System.setIn(new FileInputStream("src/sds/DAY01/P1103/input.txt"));
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        M = sc.nextInt();

        board = new String[N][M];
        for (int i = 0; i < N; i++){
            board[i] = sc.next().split("");
        }
    }

    private static void dfs(){
        // 체크인

        // 목적지인가?

        // 연결된 곳 순회

        // 갈 수 있는가?

        // 간다

       // 체크아웃
    }
}
