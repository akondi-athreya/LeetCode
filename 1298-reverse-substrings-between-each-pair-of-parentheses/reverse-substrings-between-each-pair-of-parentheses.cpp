class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        string res;
        for(char &i : s){
            if(i == '(') st.push(res.length());
            else if(i == ')'){
                int l = st.top();
                st.pop();
                reverse(begin(res)+l , end(res));
            }
            else res.push_back(i);
        }
        return res;
    }
};