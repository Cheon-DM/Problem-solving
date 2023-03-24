package sds.DAY03.P1655;

import java.io.*;
import java.util.Comparator;
import java.util.PriorityQueue;

public class Main {

    static int N;
    static PriorityQueue<Integer> maxHeap, minHeap;

    /**
     * maxHeap과 minHeap을 활용해 중간 값 찾아내기 <br>
     * maxHeap : 작은 수를 최대 힙에 저장함. root는 항상 중간 값 <br>
     * minHeap : 큰 수를 최소 힙에 저장함. root는 항상 중간 값 <br>
     */

    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("src/sds/DAY03/P1655/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        N = Integer.parseInt(br.readLine());

        maxHeap = new PriorityQueue<>(Comparator.reverseOrder());
        minHeap = new PriorityQueue<>();
        for (int i = 0; i < N; i++) {
            int num = Integer.parseInt(br.readLine());

            if (i == 0){ // 처음은 최대 힙에 넣어줌
                maxHeap.add(num);
            }

            else if (i % 2 == 1){ // i = 1, 3, 5, .. 인 경우 최소 힙에 넣음
                minHeap.add(num);
                swap();
            }

            else { // i = 2, 4, 6, .. 인 경우 최대 힙에 넣음
                maxHeap.add(num);
                swap();
            }

            bw.write(maxHeap.peek() + "\n");
        }

        bw.flush();
        bw.close();
        br.close();
    }

    static void swap(){
        Integer leftPeek = maxHeap.peek();
        Integer rightPeek = minHeap.peek();
        if (leftPeek > rightPeek){
            leftPeek = maxHeap.poll();
            rightPeek = minHeap.poll();
            minHeap.add(leftPeek);
            maxHeap.add(rightPeek);
        }
    }
}
