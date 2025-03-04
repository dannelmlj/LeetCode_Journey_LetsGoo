class Solution {
public:
    int countPrimes(int n) {
        vector<bool> mark (n, false);
        for (int p = 2; p < n; ++p){
            if (mark[p]) continue;
            for (int q = p * 2; q < n; q += p) mark[q] = true;
        }
        int count = 0;
        for (int p = 2; p < n; ++p) {
            if (!mark[p]) count++;
        }
        return count;
    }
};