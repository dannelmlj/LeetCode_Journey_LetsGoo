class Solution {
public:
    static bool cmp (pair<int,int> a, pair<int,int> b){
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> myMap;
        vector<pair<int,int>> customMap(nums.size()+1);

        vector<int> ans;

        for (auto i: nums){
            myMap[i]++;
        }

        for (auto i: myMap){
            customMap.push_back(i);
        }

        sort(customMap.begin(), customMap.end(), cmp);
        for(int i=0; i<k; i++){
            ans.push_back(customMap[i].first);
        }



        return ans;
    }
};