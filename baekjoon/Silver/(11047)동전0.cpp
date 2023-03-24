#include <iostream>

using namespace std;

int main (){
    int N, K; // n개의 줄, K원
    int a[11];
    cin >> N >> K;
    
    for (int i=0; i< N; i++){
        cin >> a[i];
    }

    int count = 0;
    for(int i = N-1; i>=0; i--){
        count += K/a[i];
        K = K % a[i];
    }

    cout << count <<endl;
}