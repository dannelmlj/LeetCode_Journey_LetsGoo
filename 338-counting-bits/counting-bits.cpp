class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> output;
        for (int i=0; i<=n; i++){
            // int bits = log2(i) + 1;
            string num =bitset<17>(i).to_string();
            int numss = 0;
            for (int j=0; j<num.length();j++){
                if (num[j] == '1'){
                    numss++;
                }
            }
            output.push_back(numss);
        }
        return output;
    }
};