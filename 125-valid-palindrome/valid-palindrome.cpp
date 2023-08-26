class Solution {
public:
    bool isPalindrome(string s) {

        erase_if(s, [](char const &c) {
            return !std::isalnum(c);
        });
        string str = "";

        for (int i=0; i< s.length(); i++){
            str += tolower(s[i]);
        }
        
        int sz = str.length()-1;
        for (int i=0; i<str.length()/2; i++){
            if (str[i] != str[sz]){
                return false;
            }
            sz--;
        }
        return true;
    }
};