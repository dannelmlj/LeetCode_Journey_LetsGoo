class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t output =0;
        string r = "";
        string yay = bitset<32>(n).to_string();
        for (int i=yay.length() - 1; i>=0; i--){
           r +=yay[i];
        }
        int counter = 0;

        for (int i=31; i>=0 ; i--){
            if (r[i] == '1'){
                output += pow(2,counter);
            }
            counter++;
        }
        // output = stoi(r,0,2);
        return output;

    }
};