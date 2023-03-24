package sds.DAY02.P2517;

import java.io.*;
import java.util.Arrays;

/**
 * 인덱스 = 등수
 * 1. 실력 오름차순으로 정렬
 * 2. 실력 1이하인 사람부터 넣음 (1명이라고 넣기)
 * ex) 실력 1인 사람 넣기 -> 실력 2인 사람 넣기 -> 실력 4인 사람 넣기
 *   이 때, Q[1~6]을 날려서 1~6등 중 실력이 4이하인 사람 찾기
 */

class Player implements Comparable<Player>{
    int rank;
    int skill;

    public Player(int rank, int skill) {
        this.rank = rank;
        this.skill = skill;
    }

    @Override
    public int compareTo(Player o) {
        int comp1 = skill - o.skill;
        if (comp1 == 0){
            return rank - o.rank;
        } else {
            return comp1;
        }
    }
}

public class Main {

    static int N;
    static int[] tree;
    static Player[] Players;
    static int[] answer;

    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("src/sds/DAY02/P2517/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        N = Integer.parseInt(br.readLine());
        Players = new Player[N];
        int S = 1;
        while (S < N){ // ex) n = 6 --> s = 8필요
            S *= 2;
        }

        tree = new int[2*S];

        for (int i = 0; i < N; i++) {
            int skill = Integer.parseInt(br.readLine());
            Players[i] = new Player(i+1, skill);
        }

        Arrays.sort(Players);
        answer = new int[N+1];

        for (int i = 0; i < Players.length; i++){
            int target = Players[i].rank;
            update(1, S, 1, target, 1);
            int goFront = query(1, S, 1, 1, target - 1);

            if (target - goFront >= 1){
                answer[target] = target - goFront;
            }
        }

        for (int i = 1; i <= N; i++) {
            bw.write(answer[i] + "\n");
        }

        bw.flush();
        bw.close();
        br.close();
    }

    static void update(int left, int right, int node, int target, int diff){
        // 연관 없음
        if (target < left || right < target) return;

        // 연관 있음
        tree[node] += diff; // 현재 노드에 diff 반영
        if (left != right) { // 자식 노드가 있는 경우
            int mid = (left + right) / 2;
            update(left, mid, node * 2, target, diff);
            update(mid+1, right, node * 2 + 1, target, diff);
        }
    }

    static int query(int left, int right, int node, int queryLeft, int queryRight){
        // 연관 없음
        if (queryRight < left || right < queryLeft) return 0;

        // 판단 가능
        if (queryLeft <= left && right <= queryRight){
            return tree[node];
        }

        // 판단 불가
        int mid = (left + right) / 2;
        int leftResult = query(left, mid, node * 2, queryLeft, queryRight);
        int rightResult = query(mid + 1, right, node * 2 + 1, queryLeft, queryRight);
        return leftResult + rightResult;
    }
}

