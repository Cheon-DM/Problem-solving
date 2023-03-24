#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, N;
vector<int> Jon;
vector<int> Chloe;

int DynamicProgramming(){
    // Jon-Chloe
    int thisSum = 0;
    int maxSum = 0;
    vector<int> cache(N, 0);
    for (int i = 0; i < N; i++){
        thisSum = max(thisSum + Jon[i], 0);
        maxSum = max(maxSum, thisSum);
        cache[i] = thisSum;
    }

    for (int i = 0; i < N; i++){
        cout << i << ": " << cache[i] << "\n";
    }

    return maxSum;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    for (int Testcase = 1; Testcase <= T; Testcase++){
        cin >> N;
        Jon.assign(N, 0);
        Chloe.assign(N, 0);
        for (int i = 0; i < N; i++){
            cin >> Jon[i];
        }
        for (int i = 0; i < N; i++){
            cin >> Chloe[i];
        }
        cout << "maxSum: " << DynamicProgramming();
    }
}

/*
4
10
10 5 -3 2 -10 7 2 19 3 15
5 -14 2 5 -4 -10 9 11 -2 5
14
16 13 -18 -14 -7 0 -9 13 18 -1 9 -4 -17 17
12 14 6 16 4 -11 9 16 -6 0 6 14 0 4
18
2 15 8 17 -18 -18 -10 8 -14 1 18 12 -5 17 -19 -5 -2 -16
-17 3 10 -15 -4 -12 -9 -3 7 11 5 16 -16 17 -19 15 16 -13
13
-13 -17 -1 -17 -10 -2 -2 -16 -15 -3 -10 -3 -8
-8 -16 -18 -2 -15 -17 -18 -11 -12 -15 -16 -3 -5
*/