class Solution {
public:
    int longestPalindrome(string s) {
        //Base Case
        if (s.length() <= 1){
            return s.length();
        }
        unordered_map<char,int> myMap;
        int odd = 0;
        for(int i=0; i<s.length(); i++){
            myMap[s[i]]++;
            if(myMap[s[i]] %2) odd++;
            else odd--;
        }
        if (odd) return s.length() - odd + 1;
        return s.length();
    }
};