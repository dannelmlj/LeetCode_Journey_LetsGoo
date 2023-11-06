class Solution {
public:
    static bool cmp(pair<int, int>& a, 
            pair<int, int>& b) 
    { 
        return a.second > b.second; 
    } 
    int lolSort(map<int, int>& M) 
    { 
    
        vector<pair<int, int> > A; 
    
        for (auto& it : M) { 
            A.push_back(it); 
        } 
    
        std::sort(A.begin(), A.end(), cmp); 

        return A[0].first;
    }
    int majorityElement(vector<int>& nums) {
        map<int,int> myMap;
        for (int i=0; i<nums.size(); i++){
            myMap[nums[i]]++;
        }
        return lolSort(myMap);
    }
};