/**
 * Leetcode - 401
 * backtracking, bit manipulation
*/

#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

class Solution {
public:
    vector<string> answer;
    
    vector<string> readBinaryWatch(int turnedOn) {
        for (int h = 0; h < 12; h++){
            for (int m = 0; m < 60; m++){
                int hourBit = bitset<4>(h).count();
                int minuteBit = bitset<6>(m).count();

                if (hourBit + minuteBit == turnedOn){
                    answer.push_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
                }
            }
        }

        return answer;
    }
};