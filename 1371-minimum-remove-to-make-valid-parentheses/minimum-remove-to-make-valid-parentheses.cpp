class Solution {
public:
    string minRemoveToMakeValid(string s) {
       
        stack<int>st;
        unordered_map<int,int>mp;
        for(int i=0;i<s.size();i++){
            
            if (st.empty() && (s[i] == '(' || s[i] == ')')){

                st.push(i);
            }else{
                if(s[i]==')' and s[st.top()]=='(' ){
                    st.pop();
                }
                else{
                    if(s[i]=='(' or s[i]==')'){
                        st.push(i);
                    }
                }
            }
        }
        while(!st.empty()){
            mp[st.top()]=1;
            st.pop();
        }
        string ans="";
        for(int i=0;i<s.size();i++){
        if(mp.find(i)==mp.end()){
            ans+=s[i];
        }
        }
        return ans;
    }
};