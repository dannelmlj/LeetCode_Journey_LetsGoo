class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Base case
        if (nums.size() == 1) return nums[0];
        int sz = nums.size();
        vector<int> dp(sz,0);
        dp[0] = nums[0];
        int maxx = dp[0];
        for (int i=1; i<nums.size(); i++){
            if (dp[i-1] > 0){
                dp[i]= nums[i] + dp[i-1];
            } else {
                dp[i]= nums[i];
            }
            maxx = max(maxx, dp[i]);
        }
        return maxx;
    }
};