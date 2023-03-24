#include <iostream>

using namespace std;

int n, s; // 크기 n, 소트 횟수 s
int a[50]; // 배열 a

void compare(int a[], int n){ // 내림차순 정렬, 버블정렬
    if (s == 0) return;

    for (int i = 0; i < n; i++){
        int max = a[i];
        int max_i = i;
        for (int j = i+1; j < n && j <i + 1 + s; j++){
            if (max < a[j]) {
                max = a[j];
                max_i = j;
            }
            
        }

        
        s -= max_i - i;

        for (int j = max_i; j > i; j--){
            a[j] = a[j-1];
        }
        a[i] = max;

        if (s ==0) return;
    }

}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i =0; i< n;i++){
        cin >> a[i];
    }
    cin >> s;

    compare(a, n);

    for (int i = 0; i <n; i++){
        cout << a[i] << " ";
    }
}