/**
 * programmers - 뒤에 있는 큰 수 찾기
 * priority queue, stack
 */

import java.util.*;

class Solution {
    public int[] solution(int[] numbers) {
        int[] answer = new int[numbers.length];
        
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[1] - b[1]);
        
        for (int i = 0; i < numbers.length; i++){
            int value = numbers[i];
            
            while(!pq.isEmpty() && pq.peek()[1] < value){
                answer[pq.poll()[0]] = value;
            }
            
            pq.add(new int[] {i, value});
        }
        
        while(!pq.isEmpty()){
            answer[pq.poll()[0]] = -1;
        }
        
        return answer;
    }
}