package sds.DAY02.P2096;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int[] dp_min = new int[3], dp_max = new int[3];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());

        for (int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());

            int x0 = Integer.parseInt(st.nextToken());
            int x1 = Integer.parseInt(st.nextToken());
            int x2 = Integer.parseInt(st.nextToken());

            if (i == 0){
                dp_max[0] = dp_min[0] = x0;
                dp_max[1] = dp_min[1] = x1;
                dp_max[2] = dp_min[2] = x2;
            } else {
                // max
                int y0 = dp_max[0], y1 = dp_max[1], y2 = dp_max[2];
                dp_max[0] = Math.max(y0, y1) + x0;
                dp_max[2] = Math.max(y2, y1) + x2;
                dp_max[1] = Math.max(Math.max(y0, y1), y2) + x1;

                // min
                int z0 = dp_min[0], z1 = dp_min[1], z2 = dp_min[2];
                dp_min[0] = Math.min(z0, z1) + x0;
                dp_min[2] = Math.min(z2, z1) + x2;
                dp_min[1] = Math.min(Math.min(z0, z1), z2) + x1;
            }
        }

        System.out.print(Math.max(Math.max(dp_max[0], dp_max[1]), dp_max[2]) + " ");
        System.out.println(Math.min(Math.min(dp_min[0], dp_min[1]), dp_min[2]));
    }
}
