package sds.DAY03.P9202;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

class TrieNode {
    TrieNode[] children = new TrieNode[26];
    boolean isEnd;
    boolean isHit;

    // 자식 체크
    boolean hasChild(char c) {
        return children[c - 'A'] != null;
    }

    // 자식 가져오기
    TrieNode getChild(char c) {
        return children[c - 'A'];
    }

    // isHit clear
    void clearHit() {
        this.isHit = false;
        for (TrieNode child : children) {
            if (child != null) {
                child.clearHit();
            }
        }
    }
}

public class Solution {

    static int w, b;
    static int[] dx = { 0, 1, 1, 1, 0, -1, -1, -1};
    static int[] dy = { -1, -1, 0, 1, 1, 1, 0, -1};
    static int[] score = {0, 0, 0, 1, 1, 2, 3, 5, 11};
    static char[][] board = new char[4][4];
    static boolean[][] visited;
    static String longestWord = "";
    static int sum, count;
    static StringBuilder sb = new StringBuilder();
    static TrieNode root = new TrieNode();

    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("src/sds/DAY03/P9202/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        w = Integer.parseInt(br.readLine());

        for (int i = 0; i < w; i++){
            insert(br.readLine());
        }

        br.readLine();

        b = Integer.parseInt(br.readLine());
        for (int i = 0; i < b; i++){
            for (int j = 0; j < 4; j++){
                board[j] = br.readLine().toCharArray();
            }

            sum = 0;
            count = 0;
            visited = new boolean[4][4];
            longestWord = "";
            root.clearHit();

            for (int m = 0; m < 4; m++){
                for (int n = 0; n < 4; n++){
                    search(m, n, root);
                }
            }

            System.out.print(sum);
            System.out.print(" ");
            System.out.print(longestWord);
            System.out.print(" ");
            System.out.println(count);

            br.readLine();
        }
    }

    static void insert(String word) {
        TrieNode current = root;
        for (int i = 0; i < word.length(); i++){
            char c = word.charAt(i);

            if (!current.hasChild(c)) {
                current.children[c-'A'] = new TrieNode();
            }

            current = current.getChild(c);
        }
        current.isEnd = true;
    }

    static void search(int x, int y, TrieNode node) {
        // 목적지에 도달했는가 ?
        if (node.isEnd && !node.isHit){
            node.isHit = true;
            sum += score[sb.length()];
            count++;

            String foundAnswer = sb.toString();
            if (compare(longestWord,foundAnswer) > 0){
                longestWord = foundAnswer;
            }
        }

        // 연결된 곳 순회
        for (int i = 0; i < 8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 갈 수 있는가
            if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4 && !visited[nx][ny]) { // 맵 범위, 방문 X
                if (node.hasChild(board[x][y])){
                    // 체크인
                    visited[x][y] = true;
                    sb.append(board[x][y]);

                    search(nx, ny, node.getChild(board[x][y]));

                    // 체크아웃
                    visited[x][y] = false;
                    sb.deleteCharAt(sb.length()-1);
                }
            }
        }


    }

    private static int compare(String o1, String o2) {
        int comp1 = o2.length() - o1.length();
        if (comp1 == 0){ // string 오름차순
            return o1.compareTo(o2);
        } else return comp1;
    }
}
