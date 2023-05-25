class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int toRight[n][m];

        for (int i = 0; i < n; i++) {
            int counter = 0;
            for (int j = m-1; j >=0 ; j--) {
                if (mat[i][j] == 1) {
                    counter++;
                }
                else{
                    counter=0;
                }
                toRight[i][j]= counter;
            }
        }

        int output=0;
        for (int j = 0; j < m; j++) {
            stack<pair<int, int> > myStack;
            int tempSum = 0;
    
            for (int i = n-1; i>=0; i--){
                int c = 0;
                while (!myStack.empty() && myStack.top().first > toRight[i][j]) {
                    tempSum -= (myStack.top().second + 1) * (myStack.top().first - toRight[i][j]);
                    c += myStack.top().second + 1;
                    myStack.pop();
                }
                tempSum += toRight[i][j];
                output += tempSum;
                myStack.push({ toRight[i][j], c });
            }
        }


        return output;
    }
    
};