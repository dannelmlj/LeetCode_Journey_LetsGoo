class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> myStack;
        myStack.push(-1);
        int maxCount=0;
      
        for (int i = 0; i < s.length(); i++){
            if (s[i] == '('){
                myStack.push(i);
            } else {
                myStack.pop();
                if (myStack.empty()){
                    myStack.push(i);
                } else {
                    maxCount = max(maxCount, i - myStack.top());
                }
            }
        }

        return maxCount;
}

};