package sds.DAY04.P1735;

import java.io.*;
import java.util.StringTokenizer;

public class Main {

    static int A1, A2, B1, B2;

    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("src/sds/DAY04/P1735/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        A1 = Integer.parseInt(st.nextToken());
        B1 = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        A2 = Integer.parseInt(st.nextToken());
        B2 = Integer.parseInt(st.nextToken());

        int ja = A1 * B2 + A2 * B1;
        int mo = B1 * B2;

        int mod = gcd(ja, mo);
        ja /= mod;
        mo /= mod;

        System.out.println(ja + " " + mo);
    }

    static int gcd (int a, int b){
        while (b != 0){
            int r = a % b;
            a = b;
            b = r;
        }

        return a;
    }
}
