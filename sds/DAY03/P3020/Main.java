package sds.DAY03.P3020;

import java.io.*;
import java.util.StringTokenizer;

public class Main {

    static int N, H;
    static int[] top, bottom;
    static int[] topPoint, bottomPoint; // 높이에 해당하는 장애물 개수

    static int[] topSum, bottomSum; // 누적 합(H 높이에 넘어갈 수 있는 장애물 수)
    /**
     * 개똥벌레가 장애물을 부시는 높이는 1 ~ H-1까지 <br>
     * top에서 길이가 1인 것은 bottom에서 H-1인 것이라 생각할 수 있음.
     */

    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("src/sds/DAY03/P3020/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        H = Integer.parseInt(st.nextToken());

        top = new int[N/2];
        bottom = new int[N/2];
        topPoint = new int[H];
        bottomPoint = new int[H+1];
        for (int i = 0; i < N/2; i++) {
            bottom[i] = Integer.parseInt(br.readLine());
            bottomPoint[bottom[i]]++;
            top[i] = Integer.parseInt(br.readLine());
            topPoint[H-top[i]]++;
        }

        topSum = new int[H+1];
        for (int i = 1; i <= H; i++) {
            topSum[i] = topSum[i-1] + topPoint[i-1];
        }
        bottomSum = new int[H+1];
        for (int i = H-1; i > 0; i--) {
            bottomSum[i] = bottomSum[i+1] + bottomPoint[i];
        }

        int min = N;
        int cnt = 0;
        for (int i = 1; i <= H; i++) {
            if (min > topSum[i] + bottomSum[i]){
                min = topSum[i] + bottomSum[i];
                cnt = 1;
            }

            else if (min == topSum[i] + bottomSum[i]){
                cnt++;
            }
        }

        bw.write(min + " " + cnt + "\n");
        bw.flush();
        bw.close();
        br.close();
    }
}
