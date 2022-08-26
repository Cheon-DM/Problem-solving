class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        ransomNote_list = list(ransomNote)
        magazine_list = list(magazine)
        for x in ransomNote_list:
            if x in magazine_list:
                magazine_list.pop(magazine_list.index(x))
            else:
                return False
        
        return True