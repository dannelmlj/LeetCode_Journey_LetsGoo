class Solution {
public:
    bool isValid(string s) {
        stack<char> st; 
        for (int i=0; i<s.length(); i++){
            if (s.length() % 2 != 0){
                return false;
            }
            if (s[0] == ')' || s[0] == '}' || s[0] == ']'){
                return false;
            }
            if (s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }
            else{
                if (st.empty()) {return false;}
                if (s[i] == ')' && st.top() != '(')
                    return false;
                if (s[i] == ']' && st.top() != '[')
                    return false;
                if (s[i] == '}' && st.top() != '{')
                    return false;

                st.pop();
            }

    }
        return st.empty();

    }
};