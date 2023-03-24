package sds.DAY01.P1759;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {

    static int L, C;
    static String[] alphabet;
    static boolean[] visited;
    static final List<String> vowels = new ArrayList<>(Arrays.asList("a", "e", "i", "o", "u"));


    public static void main(String[] args) throws FileNotFoundException {
        System.setIn(new FileInputStream("src/sds/DAY01/P1759/input.txt"));
        Scanner sc = new Scanner(System.in);

        L = sc.nextInt();
        C = sc.nextInt();

        alphabet = new String[C];
        for (int i = 0; i < C; i++){
            alphabet[i] = sc.next();
        }
        Arrays.sort(alphabet);

        visited = new boolean[C];
        for (int i = 0 ; i < C; i++){
            dfs(i, 1);
        }
        System.out.println("======");
        dfs_1(-1, 0, 0, 0, "");
    }

    private static void dfs(int start, int level) {
        // 체크인 -> 중복 방문이 없기 때문에 생략이 가능하다 (밑 dfs_1 참고)
        visited[start] = true;

        // 목적지인가 ?
        if (level == L){
            int cons = 0, vow = 0;
            String str = "";
            for (int i = 0; i < C; i++){
                if (visited[i]){
                    if (vowels.contains(alphabet[i])){ // 모음인 경우
                        vow++;
                    } else { // 자음인 경우
                        cons++;
                    }
                    str += alphabet[i];
                }
            }

            if (vow >= 1 && cons >= 2){
                System.out.println(str);
            }
        }

        // 연결된 곳 순회
        for (int i = start+1; i < C; i++){
            // 갈 수 있는가 ? -> 정렬해놨기 때문에 생략 가능
            if (!visited[i]){
                // 간다
                dfs(i, level+1);
            }
        }

        // 체크아웃 -> 생략가능
        visited[start] = false;
    }

    private static void dfs_1(int start, int level, int cons, int vow, String code){

        // 목적지인가?
        if (level == L){
            if (cons >= 2 && vow >= 1) {
                System.out.println(code);
            }
        } else {
            // 연결된 곳 순회
            for (int i = start + 1; i < C; i++) {
                // 간다 - 모음
                // code를 + 형식으로 넘기는건 나중에 TLE가 발생할 수 있음. 주의 필요
                if (vowels.contains(alphabet[i])){
                    dfs_1(i, level + 1, cons , vow + 1, code + alphabet[i]);
                } else { // 간다 - 자음
                    dfs_1(i, level + 1, cons + 1, vow, code + alphabet[i]);
                }
            }
        }
    }
}
