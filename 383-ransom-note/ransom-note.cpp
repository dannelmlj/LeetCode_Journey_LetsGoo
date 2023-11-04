class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> ransom;
        map<char,int> mags;
        for (int i=0; i<magazine.length(); i++){
            mags[magazine[i]]++;
        }
        for (int i=0; i<ransomNote.length(); i++){
            auto it = mags.find(ransomNote[i]);
            if (it == mags.end()){
                return false;
            }
            else{
                mags[ransomNote[i]]--;
                if (mags[ransomNote[i]] == 0){
                    mags.erase(ransomNote[i]);
                }
            }
        }
        return true;


    }
};