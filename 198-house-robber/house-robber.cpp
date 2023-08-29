class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1){
            return nums[0];
        }
        if (nums.size() == 2){
            if (nums[0] > nums[1]){
                return nums[0];
            }
            return nums[1];
        }
        if (nums.size() == 3){
            if (nums[1] > (nums[0]+nums[2])){
                return nums[1];
            }
            return nums[0]+nums[2];
        }

        vector<int> outs;   
        for (int i = 0 ; i<nums.size(); i++){
            outs.push_back(nums[i]);
        }
        outs[2] = outs[0] + outs[2];
        for (int j=3; j<nums.size();j++){
            int first = outs[j] + outs[j-3];
            int second = outs[j] + outs[j-2];

            if (first>second){
                outs[j] += outs[j-3];
            }
            else{
                outs[j] += outs[j-2];
            }
        }
        if (outs[outs.size()-1] > outs[outs.size()-2]){
            return outs[outs.size()-1];
        }
        return outs[outs.size()-2];
    }

};