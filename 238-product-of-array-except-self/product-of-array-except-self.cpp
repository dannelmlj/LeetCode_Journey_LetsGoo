class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> prefixProduct(size);
        vector<int> suffixProduct(size);


        prefixProduct[0] = nums[0];
        for (int i = 1; i<size; i++){
            prefixProduct[i] = nums[i] * prefixProduct[i-1];
        }
        suffixProduct[size - 1] = nums[size-1];
        for (int i = size - 2; i>=0; i--){
            suffixProduct[i] = nums[i] * suffixProduct[i+1];
        }
        vector<int> ans(size);
        for (int i = 0; i < size; i++) {
            if (i == 0)
                ans[i] = suffixProduct[1];
            else if (i == size - 1)
                ans[i] = prefixProduct[size - 2];
            else
                ans[i] = prefixProduct[i - 1] * suffixProduct[i + 1];
        }

        for (auto i: prefixProduct){
            cout << i << " ";
        }
        cout << '\n';
        for (auto i: suffixProduct){
            cout << i << " ";
        }
        cout << '\n';
        for (auto i: ans){
            cout << i << " ";
        }


        return ans;
    }
};