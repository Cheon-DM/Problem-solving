package sds.DAY03;

public class IndexedTree {

    static int N, M, K;
    static long[] nums = {1, 2, 3, 4, 5}; // 실제 데이터 입력 값
    static long[] tree; // 만들 트리
    static int S; // 트리에서 데이터 시작 인덱스 값

    public static void main(String[] args) {

        // 데이터 개수
        N = 5;

        // S 구하기
        S = 1;
        while (S < N){
            S *= 2;
        }

        // 트리 크기 설정
        tree = new long[S * 2];
    }

    static void init(){ // bottom-up
        // leaf = data
        for (int i = 0; i < N; i++){
            tree[S+i] = nums[i];
        }

        // 내부노드 = 자식의 합
        for (int i = S-1; i > 0; i--){
            tree[i] = tree[i*2] + tree[i*2+1];
        }
    }

    static long query(int left, int right, int node, int queryLeft, int queryRight){ // top-down
        // 연관 없음
        if (queryRight < left || right < queryLeft) {
            return 0; // 영향을 주지 않는 값 리턴
        }
        // 판단 가능 (현재 값이 쿼리에 들어옴)
        else if (queryLeft <= left && right <= queryRight){
            return tree[node];
        }
        // 판단 불가 (값이 걸쳐 있음)
        else {
            int mid = (left + right) / 2;
            long leftResult = query(left, mid, node*2, queryLeft, queryRight);
            long rightResult = query(mid+1, right, node*2 + 1, queryLeft, queryRight);
            return leftResult + rightResult;
        }
    }

    static long queryBU(int queryLeft, int queryRight) { // bottom-up : 그림 그려서 해보기
        long sum = 0;
        int left = S + queryLeft - 1;
        int right = S + queryRight - 1;

        while (left <= right) {
            if (left % 2 == 1){ // 홀수
                sum += tree[left++];
            }

            if (right % 2 == 0) { // 짝수
                sum += tree[right--];
            }

            left /= 2;
            right /= 2;
        }


        return sum;
    }

    static void update(int left, int right, int node, int target, long diff){ // top-down
        // 연관 없음
        if (target < left || right < target) {
        }

        else { // 연관 있음
            // 현재 노드 갱신
            tree[node] += diff;

            // 연관 있음 - 내부 노드
            if (left != right){
                int mid = left + right;
                update(left, mid, node*2, target, diff);
                update(mid+1, right, node*2+1, target, diff);
            }
        }
    }

    static void updateBU(int target, long value) {
        int node = S + target - 1;
        tree[node] = value;
        node /= 2;

        while (node > 0){ // root에 도달할 때 까지
            tree[node] = tree[node*2] + tree[node*2+1];
            node /= 2;
        }
    }
}
