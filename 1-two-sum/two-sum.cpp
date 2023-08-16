class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i,j;
        bool found=false;
        vector<int> output;
        for (i = 0; i <= nums.size() - 2; i++){
            for (j=1; j<nums.size(); j++){
                if (nums[i] + nums[j] == target && i != j){
                    found= true;
                    break;
                }
            }
            if (found){
                break;
            }
        }
        output.push_back(i);
        output.push_back(j);
        return output;
    }
};