class Solution {
public:
    int minSwaps(string s) {
        int countZero = 0;
        int countOne = 0;

        int countStartWithOne = 0;
        int countStartWithZero = 0;

        for (int i = 0; i < s.length(); i++){
            if (s[i] == '1'){
                countOne++;
            } else {
                countZero++;
            }

            if(i % 2 == 0){
                if (s[i] != '1'){
                    countStartWithOne++;
                } else {
                    countStartWithZero++;
                }
            } else {
                if (s[i] == '1'){
                    countStartWithOne++;
                } else {
                    countStartWithZero++;
                }
            }


        }

        if (abs(countOne - countZero) > 1){
            return -1;
        }
        // cout << countStartWithOne << endl;
        // cout << countStartWithZero << endl;

        // cout << "Count One: " << countOne << endl;
        // cout << "Count Zero: " << countZero << endl;

        if (countOne > countZero){
            return countStartWithOne/2;
        } else if (countOne < countZero){
            return countStartWithZero/2;
        } else {
            return countStartWithOne < countStartWithZero ? countStartWithOne/2 : countStartWithZero/2;
        }

        

        // return 0;
    }   
};