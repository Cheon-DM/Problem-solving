#include <iostream>

using namespace std;

int main(){
    // input
    int n;
    cin >> n;

    int a, b  = 0;
    int rest = n;
    a = n / 5;
    rest = rest % 5;

    while(1){
        if (a < 0){
            cout << "-1";
            return 0;
        }

        if (rest % 3 == 0){
            b = rest / 3;
            cout << a + b;
            break;
        }

        a--;
        rest = n - a * 5;
    }

    return 0;
}