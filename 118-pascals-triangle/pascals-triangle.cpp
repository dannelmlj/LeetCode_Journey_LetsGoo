class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans = {{1}};
        for (int i=2; i <= numRows; i++){
            vector<int> inside;
            for (int j=0; j < i; j++){
                if (j == 0  || j == i-1){
                    inside.push_back(1);
                } else {
                    inside.push_back(ans[i-2][j] + ans[i-2][j-1]);
                }
            }
            ans.push_back(inside);
        }

        cout << ans[0][0];
        return ans;
    }
};