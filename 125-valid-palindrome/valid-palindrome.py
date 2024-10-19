class Solution:
    def isPalindrome(self, s: str) -> bool:
        if len(s) == 1:
            return True
        s = "".join(char for char in s if char.isalpha() or char.isnumeric()).lower()
        if len(s) % 2 == 0:
            s1 = s[:len(s)//2]
            s2 = "".join(reversed(s[len(s)//2:]))
        else: 
            s1 = s[:len(s)//2]
            s2 = "".join(reversed(s[len(s)//2 + 1:]))
        if s1 == s2:
            return True
        return False
        
        