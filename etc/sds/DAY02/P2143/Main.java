package sds.DAY02.P2143;

/**
 * 1. A, B를 우선 부 배열 세트를 만들어 준 후 배열로 만듦 (O(N^2))
 * 2. 각각의 부 배열 세트를 정렬해줌 (O(N^2logN^2)) A: 오름차순, B: 내림차순
 * 3. 두 부 배열을 투 포인터를 활용해 해당 값을 구해줌 (O(N^2))
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int T, n, m;
    static int[] A, B;
    static List<Integer> subA, subB;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        T = Integer.parseInt(br.readLine());
        n = Integer.parseInt(br.readLine());

        A = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }

        m = Integer.parseInt(br.readLine());
        B = new int[m];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < m; i++) {
            B[i] = Integer.parseInt(st.nextToken());
        }

        // 부 배열 합 세트 구하기
        subA = new ArrayList<>();
        for (int start = 0; start < n; start++) {
            int sum = 0;
            for (int end = start; end < n; end++) {
                sum += A[end];
                subA.add(sum);
            }
        }

        subB = new ArrayList<>();
        for (int start = 0; start < m; start++) {
            int sum = 0;
            for (int end = start; end < m; end++) {
                sum += B[end];
                subB.add(sum);
            }
        }

        // 부 배열 세트 정렬
        Collections.sort(subA);
        Collections.sort(subB);

        // 투 포인터 이용해 합 구하기 (A는 앞에서, B는 뒤에서 접근하기)
        int p1 = 0, p2 = subB.size()-1;
        long cnt = 0;

        while (p1 < subA.size() && p2 >= 0){
            int sum = subA.get(p1) + subB.get(p2);

            if (sum == T){ // 합 구함

                long a = subA.get(p1);
                long b = subB.get(p2);
                long cntA = 0, cntB = 0;

                while (p1 < subA.size() && subA.get(p1) == a){ // 부 배열 합이 a인 개수 구하기
                    cntA++;
                    p1++;
                }

                while (p2 >= 0 && subB.get(p2) == b){ // 부 배열 합이 b인 개수 구하기
                    cntB++;
                    p2--;
                }

                // a*b = 총 가능한 부 배열 합
                cnt += cntA * cntB;
            }

            else if (sum < T){
                p1++;
            }

            else { // sum > T
                p2--;
            }
        }

        System.out.println(cnt);
    }
}