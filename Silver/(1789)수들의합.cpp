#include <iostream>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main(){
    fio;
    
    // input
    long long s; cin >> s;

    // solution
    long long sum = 0;
    int num = 1;
    int count = 0;

    while (1){
        sum += num;
        count++;

        if (sum > s){
            count--;
            break;
        }

        num++;
    }

    cout << count;

    return 0;
}

// greedy