class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        unordered_map<char,int> sMap;
        unordered_map<char,int> tMap;

        for (auto i: s){
            sMap[i]++;
        }
        for (auto i: t){
            tMap[i]++;
        }
        for (auto i: tMap){
            if (sMap[i.first] != i.second) return false;
        }
        return true;
    }
};