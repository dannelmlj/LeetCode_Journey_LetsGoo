class Solution {
public:
    void recurse(vector<int>& dp,vector<int>& cost, int start, int accumulate){

        if (start >= cost.size()){
            if (accumulate < dp[cost.size()]){
                dp[cost.size()] = accumulate;
            }
            return;
        }
        if (accumulate < dp[start]){
            dp[start] = accumulate;
        }
        // Jump Once
        recurse(dp, cost, start+1, accumulate + cost[start]);
        // Jump Twice
        recurse(dp, cost, start+2, accumulate + cost[start]);

    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1, INT_MAX);
        dp[0] = 0;
        dp[1] = 0;

        for (int i=2; i< dp.size(); i++){
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }

        // recurse(dp, cost, 0, 0);
        // recurse(dp, cost, 1, 0);
        return dp[cost.size()];

    }
};