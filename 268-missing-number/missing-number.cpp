class Solution {
public:
    int missingNumber(vector<int>& nums) {
        map<int,int> mymap;
        int num;
        for (int i=0; i<=nums.size(); i++){
            mymap.insert({i,i});
        }
        for (int i=0; i<nums.size(); i++){
            mymap.erase(nums[i]);
        }
        for (int i=0; i<=nums.size(); i++){
            if (mymap.find(i) != mymap.end()){
                num = i;
            }
        }

        return num;
    }
};