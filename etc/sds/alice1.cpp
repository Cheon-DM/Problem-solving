#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int T, N;

int checkSquare(int n){
    int answer = 0;
    int a = sqrt(n);
    if (a*a == n){
        answer = 1;
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;
    for (int test = 1; test <= T; test++){
        cin >> N;
        vector<int> v(N);
        for (int i = 0; i < N; i++){
            cin >> v[i];
        }
        sort(v.begin(), v.end());

        int _max = 0;

        do {
            int result = 0;
            for (int i = 0; i < N; i++){
                if (i == N-1){
                    result += checkSquare(v[i] + v[0]);
                } else {
                    result += checkSquare(v[i]+v[i+1]);
                }                
            }
            if (_max < result) {
                _max = result;
            }
        } while (next_permutation(v.begin(), v.end()));

        
        cout << "#" << test << " " << _max << endl;
    }
}