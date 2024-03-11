class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> myset;
        for (int i=0 ; i<nums.size(); i++){
            myset.insert(nums[i]);
            if (myset.size() != i+1){
                return true;
            }
        }
        return false;
    }
};