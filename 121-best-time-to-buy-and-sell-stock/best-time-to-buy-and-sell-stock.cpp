class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minss = prices[0];
        int maxxx = 0;
        for (int i=1 ; i<prices.size(); i++){
            maxxx = max(maxxx, prices[i]-minss);
            minss =  min(minss,prices[i]);
        }
        return maxxx;
    }
};