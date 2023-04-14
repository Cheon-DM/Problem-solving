/**
 * programmers - 시소 짝꿍
 * hashmap
 */

import org.junit.Assert;
import org.junit.Test;
import java.util.*;

public class Solution {

    public long solution(int[] weights){
        long answer = 0;
        Map<Integer, Integer> m = new HashMap<>();

        for (int weight : weights) {
            m.put(weight, m.getOrDefault(weight, 0)+1);
        }

        List<Map.Entry<Integer, Integer>> wList = new ArrayList<>(m.entrySet());
        wList.sort(new Comparator<Map.Entry<Integer, Integer>>() {
            @Override
            public int compare(Map.Entry<Integer, Integer> o1, Map.Entry<Integer, Integer> o2) {
                return o1.getKey()-o2.getKey();
            }
        });

        for (Map.Entry<Integer, Integer> wEntry : wList) {
            // 배수 찾기
            int w = wEntry.getKey();

            // 1. 같은 비율
            if (m.containsKey(w) && m.get(w) >= 2) {
                answer += ((long) m.get(w) * (m.get(w) - 1)) / 2;
            }

            // 2. 2:3 비율
            if (w % 2 == 0 && m.containsKey(w / 2 * 3)) {
                answer += ((long) m.get(w) * m.get(w / 2 * 3));
            }

            // 3. 1:2 비율
            if (m.containsKey(w * 2)) {
                answer += ((long) m.get(w) * m.get(w * 2));
            }

            // 4. 3:4 비율
            if (w % 3 == 0 && m.containsKey(w / 3 * 4)) {
                answer += ((long) m.get(w) * m.get(w / 3 * 4));
            }
        }

        return answer;
    }

    @Test
    public void test1(){
        Assert.assertEquals(4, solution(new int[]{100, 180, 360, 100, 270}));
    }

    @Test
    public void test2(){
        Assert.assertEquals(18, solution(new int[]{100, 100, 100, 150, 150, 200, 300}));
    }
}
