class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> myMap;
        map<char,int> map2;
        
        if (s.length() != t.length()){
            return false;
        }
        for (int i=0; i< s.length(); i++){
            if (myMap.find(s[i]) != myMap.end()){
                myMap[s[i]]++;
            }
            else{
                myMap.insert({s[i],1});
            }

            if (map2.find(t[i]) != map2.end()){
                map2[t[i]]++;
            }
            else{
                map2.insert({t[i],1});
            }   
        }

        for (int i=0; i<s.length(); i++){
            if(myMap[s[i]] != map2[s[i]]){
                return false;
            }
        }
        return true;
    }
};