package sds.DAY03.P11279;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;

public class Main {

    static int N;

    // MaxHeap << 따로 만들어보기
    static PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());

    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("src/sds/DAY03/P11279/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());

        for (int i = 0; i < N; i++) {
            int num = Integer.parseInt(br.readLine());

            if (num == 0){ // 가장 큰 값 출력 후 제거
                if (pq.isEmpty()) System.out.println(0);
                else System.out.println(pq.poll());
            }

            else { // pq에 넣기
                pq.add(num);
            }
        }
    }
}

class MaxHeap {

    List<Integer> list;

    public MaxHeap() {
        list = new ArrayList<>(100001);
        list.add(0);
    }

    public void insert(int val) {
        // 1. 마지막에 추가
        list.add(val);

        // 2. 부모랑 조건 비교, 교환
        int current = list.size()-1;
        int parent = current / 2;
        while (true) {
            // 1. current == root : 탈출
            // 2. 부모, 자식 조건을 만족 : 탈출
            if (parent == 0 || list.get(parent) >= list.get(current)) break;

            // swap
            int tmp = list.get(parent);
            list.set(parent, list.get(current));
            list.set(current, tmp);

            current = parent;
            parent = current / 2;
        }
    }

    public int delete() {
        // 1. root 제거
        int top = list.get(1);

        // 2. 마지막 노드를 root로 이동
        list.set(1, list.get(list.size()-1));
        list.remove(list.size() - 1);

        // 3. 왼쪽, 오른쪽 중 조건이 안맞는 것 선택 후 조건에 맞게 swap
        int currentNode = 1;
        while (true) {
            int leftNode = currentNode * 2;
            int rightNode = currentNode * 2 + 1;

            if (leftNode >= list.size()) break; // leafNode

            int targetValue = list.get(leftNode);
            int targetNode = leftNode;

            if (rightNode < list.size() && targetValue < list.get(rightNode)) {
                targetNode = rightNode;
                targetNode = list.get(rightNode);
            }

            if (list.get(currentNode) < targetValue) {
                // swap
                int tmp = list.get(currentNode);
                list.set(currentNode, list.get(targetNode));
                list.set(targetNode, tmp);
                currentNode = targetNode;
            } else break;
        }

        return top;
    }
}
