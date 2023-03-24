package sds.DAY01.P1062;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {

    static int N, K;
    static int answer;
    static String[] words;
    static boolean[] visited;

    public static void main(String[] args) throws FileNotFoundException {
        System.setIn(new FileInputStream("src/sds/DAY01/P1062/input.txt"));
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        K = sc.nextInt();

        if (K < 5){ // 한 단어를 다 읽으려면 5개 이상 받아야함
            System.out.println(0);
            return;
        } else if (K == 26) { // 알파벳 개수만큼 있으면 모두 가능
            System.out.println(N);
            return;
        }

        words = new String[N];

        // 접두(anta), 접미(tica) 제거 후 받음.
        for (int i = 0; i < N; i++){
            String str = sc.next();
            words[i] = str.substring(4, str.length()-4);
        }

        // a, n, t, i, c 미리 방문체크
        visited = new boolean[26];
        visited[0] = true; // 'a'
        visited['n' - 'a'] = true;
        visited['t' - 'a'] = true;
        visited['i' - 'a'] = true;
        visited['c' - 'a'] = true;
        K -= 5;

        // dfs 진행
        dfs(0, 0);
        System.out.println(answer);
    }

    private static void dfs(int start, int count) {

        // 체크인
        visited[start] = true;

        // 목적지인가
        if (count == K) {
            answer = Math.max(answer, countReadable());
        } else {
            // 연결된 곳 순회
            for (int i = start+1; i < 26; i++) {
                // 갈 수 있는가?
                if (!visited[i]) {
                    // 간다
                    dfs(i, count + 1);
                }
            }
        }

        // 체크아웃
        visited[start] = false;
    }

    private static int countReadable() {
        int result = 0;
        for (String word : words) {
            boolean flag = true;

            for (int j = 0; j < word.length(); j++) {
                if (!visited[word.charAt(j) - 'a']) {
                    flag = false;
                    break;
                }
            }

            if (flag) result++;
        }
        return result;
    }
}
