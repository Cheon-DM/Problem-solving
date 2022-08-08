#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        else {
            int tmp = x;
            long reverse_x = 0;

            while (tmp > 0){
                reverse_x *= 10;
                reverse_x += tmp % 10;
                tmp /= 10;
            }

            if (x ==  reverse_x) return true;
            else return false;

        }
    }
};