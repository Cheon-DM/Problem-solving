public class Solution {

    public int solution(int storey) {
        int answer = 0;

        while (storey != 0){
            int r = storey % 10;

            if (r >= 6){ // 36 -> 40으로 만들고 -10 4번
                storey += (10 - r);
                answer += (10 - r);
            }

            else if (r == 5 && (storey / 10) % 10 >= 5){ // 65 -> 70으로 만들고 100으로 만들어서 계산하는 것이 더 적은 경우
                storey += (10 - r);
                answer += (10 - r);
            }

            else {
                answer += r;
            }

            storey /= 10;
        }

        return answer;
    }
}
