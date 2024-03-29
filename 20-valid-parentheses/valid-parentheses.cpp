class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0 ; i<s.size() ; i++){
            if(st.empty() && (s[i]==')' || s[i]=='}' || s[i]==']')){
                return false;
            }
            if(!st.empty() && st.top()=='(' && s[i]==')'){
                st.pop();
            }
            else if(!st.empty() && st.top()=='{' && s[i]=='}'){
                st.pop();
            }
            else if(!st.empty() && st.top()=='[' && s[i]==']'){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        if(st.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};