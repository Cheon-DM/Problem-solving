#include <iostream>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int dp[1001][1001] = {0, };
int main(){
    fio;
    string sen1, sen2;
    cin >> sen1 >> sen2;

    for (int i = 1; i <= sen1.length(); i++){
        for (int j = 1; j <= sen2.length(); j++){
            if (sen1[i-1] == sen2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }

            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << dp[sen1.length()][sen2.length()];

}
