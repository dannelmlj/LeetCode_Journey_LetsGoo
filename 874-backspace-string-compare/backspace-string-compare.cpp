class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string realS = "";
        string realT = "";
        
        for (int i=0; i< s.length(); i++){
            if (s[i] == '#'){
                if(realS.length()>=1){
                    realS.pop_back();
                }
                else{
                    realS = "";
                }
            }
            else{
                realS += s[i];
            }
        }

        for (int i=0; i< t.length(); i++){
            if (t[i] == '#'){
                if(realT.length()>=1){
                    realT.pop_back();
                }
                else{
                    realT = "";
                }
            }
            else{
                realT+= t[i];
            }
        }
        if (realS.compare(realT) == 0){
            return true;
        }
        return false;
    }
};