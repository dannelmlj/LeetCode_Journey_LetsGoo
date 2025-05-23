class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() <= 1){
            return nums[0];
        }
        if (nums.size() == 2){
            return max(nums[0], nums[1]);
        }
        vector<int> dp(nums.size());

        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = nums[0] + nums[2];

        for (int i=3; i<nums.size(); i++){
            dp[i] = max(nums[i] + dp[i-2], nums[i] + dp[i-3]);
        }

        return max(dp[nums.size()-2], dp[nums.size()-1]);

              
    }
};