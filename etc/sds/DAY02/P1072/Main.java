package sds.DAY02.P1072;

import java.io.*;
import java.util.StringTokenizer;

public class Main {

    static long X, Y, Z;

    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("src/sds/DAY02/P1072/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        X = Integer.parseInt(st.nextToken());
        Y = Integer.parseInt(st.nextToken());

        Z = Y * 100 / X;
        if (Z >= 99){
            System.out.println(-1);
        } else {
            long answer = binarySearch(X);
            System.out.println(answer);
        }

    }

    static long binarySearch(long end){
        long start = 1;
        long mid, ratio;
        while (start <= end){
            mid = (start + end) / 2;
            ratio = (Y + mid) * 100 / (X + mid);

            if (ratio > Z){ // 비율이 커진 경우
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return start;
    }
}
