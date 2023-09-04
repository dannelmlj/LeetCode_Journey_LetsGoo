class Solution {
public:
    int search(vector<int>& nums, int target) {
        int nummm=-1;
        if (target == nums[0]){
            return 0;
        }
        if (target == nums[nums.size()-1]){
            return nums.size() - 1;
        }
        int distTop = target - nums[0];
        int distBack = nums[nums.size() - 1] - target;

        if (distTop < distBack){
            for (int i=1; i<nums.size(); i++){
                if (nums[i] == target){
                    return i;
                }
            }
        }

        for (int i=nums.size()-2; i>=0; i--){
            if (nums[i]==target){
                return i;
            }
        }
        return nummm;
    }
};