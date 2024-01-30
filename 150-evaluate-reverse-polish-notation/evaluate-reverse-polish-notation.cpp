class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        stack<string>s2;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]!="/" && tokens[i]!="*" && tokens[i]!="+" && tokens[i]!="-"){
                st.push(stoi(tokens[i]));
                
            }
            else{
                if(!st.empty()){
                int x=st.top();
                st.pop();
                int y=st.top();
                st.pop();
                int s=0;
                if(tokens[i]=="/"){
                    s=y/x;
                }
                else if(tokens[i]=="+"){
                    s=y+x;
                }
                else if(tokens[i]=="-"){
                    s=y-x;
                }
                else if(tokens[i]=="*"){
                    s=y*x;
                }
                st.push(s);
                }
            }
        }
        return st.top();
    }
};