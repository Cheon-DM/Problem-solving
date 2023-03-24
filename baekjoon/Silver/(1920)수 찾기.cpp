/**
 * baekjoon - 1920
 * data structure, sorting, binary search
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> A, v;

void Input(){
    cin >> N;
    int tmp;
    for (int i = 0; i < N; i++){
        cin >> tmp;
        A.push_back(tmp);
    }

    cin >> M;
    for (int i = 0; i < M; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
}

int binarySearch(int size, int target){
    int start = 0;
    int end = size-1;
    int mid;

    while (start <= end){
        mid = (start+end)/2;

        if (A[mid] == target) return 1;

        else if (A[mid] > target) end = mid - 1;

        else start = mid + 1;
    }

    return 0;
}

void Solution(){
    sort(A.begin(), A.end());

    for (int i = 0; i < v.size(); i++){
        int answer = binarySearch(A.size(), v[i]);
        cout << answer << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Input();
    Solution();

    return 0;
}