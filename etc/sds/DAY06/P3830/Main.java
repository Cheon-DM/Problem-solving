package sds.DAY06.P3830;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int N, M, a, b, w;
    static char commend;
    static int[] arr, weight;

    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("src/sds/DAY06/P3830/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());

            if (N == 0 && M == 0) break;

            arr = new int[N+1];
            weight = new int[N+1];

            for (int i = 1; i <= N; i++){
                arr[i] = i;
            }

            for (int i = 0; i < M; i++){
                st = new StringTokenizer(br.readLine());
                commend = st.nextToken().charAt(0);
                a = Integer.parseInt(st.nextToken());
                b = Integer.parseInt(st.nextToken());

                if (commend == '!'){
                    w = Integer.parseInt(st.nextToken());
                    union(a, b, w);
                }

                else if (commend == '?'){
                    if (find(a) == find(b)){
                        System.out.println(weight[b] - weight[a]);
                    } else {
                        System.out.println("UNKNOWN");
                    }
                }
            }
        }

    }

    static void union(int a, int b, int w){
        int aRoot = find(a);
        int bRoot = find(b);

        if (aRoot == bRoot) return;

        arr[bRoot] = aRoot;
        weight[bRoot] += (w - weight[b] + weight[a]);
    }

    static int find(int a){
        if (arr[a] == a) return a;
        else {
            // 바꾸기 전 a의 root 구하기
            int pre = find(arr[a]);

            // a의 무게는 a의 root의 무게 정보 더해주기
            weight[a] += weight[arr[a]];

            // a의 root를 refresh해줌 (pre의 root로)
            return arr[a] = find(pre);
        }
    }
}
