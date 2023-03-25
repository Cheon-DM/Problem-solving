/**
 * baekjoon - 6549
 * data structure, segment tree, divide and conquer, stack
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000000000
using namespace std;

int N, S;
long ans;
vector<int> histo;
vector<int> tree;

void setS(){
    S = 1;
    while (S < N){
        S *= 2;
    }
}

void init(){
    for(int i = S-1; i > 0; i--){
        int leftChild = tree[i*2];
        int rightChild = tree[i*2+1];
        if (leftChild == MAX){
            tree[i] = MAX;
            continue;
        } else if (rightChild == MAX){
            tree[i] = leftChild;
            continue;
        }

        int left = histo[leftChild];
        int right = histo[rightChild];

        if (left <= right){
            tree[i] = leftChild;
        } else {
            tree[i] = rightChild;
        }
    }
}

// 최소 높이의 인덱스 값
int query(int left, int right, int node, int qLeft, int qRight){
    // 연관 없음
    if (qRight < left || right < qLeft) return MAX;

    // 판단 가능
    if (qLeft <= left && right <= qRight){
        return tree[node];        
    }

    // 판단 불가
    int mid = (left + right) / 2;
    int leftValue = query(left, mid, node*2, qLeft, qRight);
    int rightValue = query(mid+1, right, node*2+1, qLeft, qRight);

    if (leftValue == MAX) return rightValue;
    if (rightValue == MAX) return leftValue;
    if (histo[leftValue] <= histo[rightValue]){
        return leftValue;
    } else {
        return rightValue;
    }
}

long getMax(int start, int end){
    long maxWidth, tmp;
    // start~end에서 최소높이의 인덱스 구하기
    int minIdx = query(1, S, 1, start, end);
    
    maxWidth = (long) (end-start+1) * histo[minIdx];

    if (start == end) return maxWidth;

    if (start <= minIdx - 1){
        maxWidth = max(maxWidth, getMax(start, minIdx - 1));
    }

    if (end >= minIdx + 1){
        maxWidth = max(maxWidth, getMax(minIdx + 1, end));
    }

    return maxWidth;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while(1){
        cin >> N;

        // end
        if (N == 0) break;

        // init
        ans = 0;
        setS();
        histo.assign(N+1, 0);
        tree.assign(2*S, MAX);

        for (int i = 1; i <= N; i++){
            cin >> histo[i];
            tree[S+i-1] = i;
        }

        init();

        ans = getMax(1, N);
        cout << ans << "\n";
    }


    return 0;
}