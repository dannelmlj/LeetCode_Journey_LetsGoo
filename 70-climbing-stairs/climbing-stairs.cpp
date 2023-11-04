class Solution {
public:
    int climbStairs(int n) {
        // Base case
        if (n<=2) return n;

        int one = 2;
        int two = 1;
        int out = 0;
        for (int i=2; i<n; i++){
            out = two + one;
            two = one;
            one = out;
        }
        return out;
    }
};