#include <iostream>
#include <cmath>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using ll = long long;
using namespace std;

int main(){
    fio;

    ll t, x, y;
    ll cur;
    cin >> t;
    for (int i = 0 ; i < t ; i++){
        cin >> x >> y;

        if (y-x == 1) {
            cout << 1 << "\n";
        }

        if (y-x == 2) {
            cout << 2 << "\n";
        }

        if (y-x == 3) {
            cout << 3 << "\n";
        }

        cur = 2;

        while(y -x > 3){
            if (y-x == pow(cur,2)){
                cout << 2 * cur - 1 << "\n";
                break;
            }

            else if (y-x < pow(cur+1, 2)){
                int div = (pow(cur+1, 2)+pow(cur, 2))/2;
                if (y-x <= div){
                    cout << 2 * cur << "\n";
                    break;
                }

                else{
                    cout << 2 * cur + 1 << "\n";
                    break;
                }
            }

            else cur++;
        }
    }

    return 0;
}