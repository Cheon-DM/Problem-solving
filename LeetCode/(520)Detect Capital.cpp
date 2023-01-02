/**
 * leetcode - 520
 * string
*/

class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt = 0;        
        // First word is capital
        if (isupper(word[0])){
            cnt++;
            for (int i = 1; i < word.size(); i++){
                if (islower(word[i])) continue;
                else {
                    cnt++;
                } 
            }
            if (cnt == 1 || cnt == word.size()) return true;
            else return false;
        }

        // First word is not capital
        else {
            for (int i = 1; i < word.size(); i++){
                if (islower(word[i])) continue;
                else {
                    return false;
                } 
            }
            return true;
        }
    }
};