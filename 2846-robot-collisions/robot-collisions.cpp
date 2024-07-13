class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> ai(n);
        for(int i=0 ; i<n ; i++){
            ai[i] = i;
        }
        auto lambda = [&](int &i , int &j){
            return positions[i] < positions[j];
        };

        sort(begin(ai) , end(ai) , lambda);
        vector<int> res;
        stack<int> st;
        for(int & curr : ai){
            if(directions[curr] == 'R'){
                st.push(curr);
            }
            else{
                while(!st.empty() && healths[curr]>0){
                    int top = st.top();
                    st.pop();
                    if(healths[top] > healths[curr]){
                        healths[top] -= 1;
                        healths[curr] = 0;
                        st.push(top);
                    }
                    else if(healths[top] < healths[curr]){
                        healths[curr] -=1;
                        healths[top] = 0;
                    }
                    else{
                        healths[curr] = 0;
                        healths[top] = 0;
                    }
                }
            }
        }

        for(int i=0 ; i<n ; i++){
            if(healths[i] > 0) res.emplace_back(healths[i]);
        }
        return res;
    }
};