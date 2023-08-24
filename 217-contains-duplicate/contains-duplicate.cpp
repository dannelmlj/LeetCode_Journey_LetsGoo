class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> myMap;

        for (int i=0; i<nums.size(); i++){
            if (myMap.find(nums[i]) != myMap.end()){
                return true;
            }
            myMap.insert({nums[i],1});
        }
        return false;
    }
};