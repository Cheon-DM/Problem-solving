#include <iostream>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr)
using namespace std;
bool check[10001] = {false};

int d(int num){
    int sum = num;

    while(num != 0){
        sum += (num % 10);
        num /= 10;
    }

    return sum;
}

int main(){
    fio;
    
    for (int i = 1; i < 10001; i++){
        int num = d(i);
        if (num < 10001){
            check[num] = true;
        }
    }

    for (int i = 1; i < 10001; i++){
        if (check[i] == false){
            cout << i << "\n";
        }
    }
}