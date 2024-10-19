class Solution:
    def longestPalindrome(self, s: str) -> int:
        char_count= Counter(s)
        print(char_count)
        output = 0
        odd = False
        for _, count in char_count.items():
            if count % 2 == 0:
                output += count
            else:
                if count - 1 != 0:
                    output += count-1
                    odd = True
                else:
                    odd = True
        if odd:
            output +=1            

        
        return output