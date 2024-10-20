class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 1 or len(s) == 0:
            return len(s)

        slow = 0
        fast = 1
        str_set = {s[slow]}
        max_value = 1
        while fast < len(s) :
            if s[fast] not in str_set:
                str_set.add(s[fast])
            else:
                max_value = max(max_value, len(str_set))
                slow += 1
                fast = slow
                str_set.clear()
                str_set.add(s[slow])
                
            fast += 1
        max_value = max(max_value,len(str_set))
        return max_value
            