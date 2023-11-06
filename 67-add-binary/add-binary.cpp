class Solution {
public:
    string addBinary(string a, string b) {

        if (b.size() > a.size()){
            return addBinary(b,a);
        }

        while (b.size() != a.size()) b.insert(0,"0");

        int carry = 0;
        string result = "";
        for (int i = b.size()-1; i>=0; i--){
            if (a[i] == '1' && b[i] == '1'){
                if (carry == 1){
                    result.insert(0, "1");
                }
                else{
                    result.insert(0, "0");
                }
                carry = 1;
            }
            else if (a[i] == '1' && b[i] == '0' || a[i] == '0' && b[i] == '1'){
                if (carry == 1){
                    result.insert(0, "0");
                }
                else{
                    result.insert(0, "1");
                }
            }
            else if (a[i] == '0' && b[i] == '0'){
                if (carry == 1){
                    result.insert(0, "1");
                }
                else{
                    result.insert(0, "0");
                }
                carry = 0;
            }
            if (i == 0 && carry == 1){
                result.insert(0, "1");
            }
        }
        cout << result;

        return result;
    }
};