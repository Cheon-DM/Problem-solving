#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main(){
    int book, carry, input;
    cin >> book >> carry;
    
    int result = 0;
    int index = 0;

    vector<int> list;
    for (int i = 0; i < book; i++){
        cin >> input;
        list.push_back(input);
        if (input < 0) index++;
    }

    sort(list.begin(), list.end());

    // 음수
    for (int i = 0; i < index; i = i + carry){
        result += 2 * abs(list[i]);
    }

    // 양수

    for (int i = book-1; i >= index; i = i - carry){
        result += 2 * list[i];
    }

    // 절대값이 가장 큰 것 = 왕복 X
    result -= max(abs(list[0]), abs(list[book-1]));
    cout << result << "\n";
    return 0;
}

/*
양수 음수 구분 필요
마지막에 큰 쪽으로 가고 꽉채워서 가서 동선 낭비 줄이기.
-39 -37 / -29 -28 / -6 / 2 11
 = 22 + 12 + 58 + 39 = 34 + 97 = 131
-45 -26 -18 / -9 -4 / 22 40 50
 = 90 + 18 + 50 = 158
-1 / 3 / 4 5 / 6 11
 = 2 + 6 + 10 + 11 = 29
*/