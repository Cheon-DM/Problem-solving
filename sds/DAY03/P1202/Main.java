package sds.DAY03.P1202;

/**
 * 1. PQ(가장 비싼 보석 top)
 * 2. 가방을 먼저 오름차순으로 정렬 : O(NlogN)
 * 3. 보석을 가벼운 순으로 정렬 : O(NlogN)
 * 4. PQ에 가방에 넣을 수 있는 보석들 모두 넣기 : O(NlogN)
 * 5. 다 넣은 후 top 빼내어 가방에 넣기 : O(NlogN)
 *  ==> O(NlogN)
 */

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Pair implements Comparable<Pair>{
    int m;
    int v;
    public Pair(int m, int v) {
        this.m = m;
        this.v = v;
    }

    @Override
    public int compareTo(Pair o) {
        int comp1 = m - o.m;
        if (comp1 == 0) {
            return o.v - v;
        } else return comp1;
    }
}

public class Main {

    static int N, K;
    static long answer;
    static int[] bags;
    static Pair[] jewels;

    // 비싼 보석이 우선순위가 높게 만듦
    static PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());

    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("src/sds/DAY03/P1202/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        jewels = new Pair[N];
        for (int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());
            int m = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());

            jewels[i] = new Pair(m, v);
        }

        bags = new int[K];
        for (int i = 0; i < K; i++){
            bags[i] = Integer.parseInt(br.readLine());
        }

        // 가방 정렬
        Arrays.sort(bags);

        // 보석 정렬 (무게순 - 오름차순)
        Arrays.sort(jewels);
        // Arrays.sort(jewels, Comparator.comparingInt(Jewel::getWeight)) 과 동일

        int index = 0;
        answer = 0;
        for (int i = 0; i < K; i++) {
            // 담을 수 있는 가방 모두 넣기
            while (index < N && bags[i] >= jewels[index].m){
                pq.add(jewels[index++].v);
            }

            // top에서 보석 빼기
            if (!pq.isEmpty()) {
                answer += pq.poll();
            }
        }

        System.out.println(answer);
    }
}
