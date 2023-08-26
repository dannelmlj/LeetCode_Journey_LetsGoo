class Solution {
public:
    int hammingWeight(uint32_t n) {
        string num = bitset<32>(n).to_string();
        int output= 0;
        for (int i=0; i<num.length(); i++){
            if (num[i] == '1'){
                output++;
            }
        }
        return output;
    }
};