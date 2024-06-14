class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        // vector<int> v(1e5+2 , 0);
        // for(int i=0 ; i<nums.size() ; i++) v[nums[i]]++;
        // vector<int> r;
        // for(int i=0 ; i<v.size() ; i++){
        //     while(v[i]>1){
        //         r.emplace_back(i);
        //         v[i]-=1;
        //     }
        // }
        // // for(int i=0 ; i<r.size() ; i++) cout<<r[i]<<endl;
        // sort(r.begin(),r.end());
        // if(r.size()==0) return 0;
        // int sum = 0 , j=0;
        // for(int i=0 ; i<v.size() ; i++){
        //     if(v[i]==0 && r[j]<i){
        //         sum+=abs(i-r[j]);
        //         j++;
        //     }
        //     if(j>=r.size()) return sum;
        // }
        // return sum;

        stack<int> st;
        vector<int> v = nums;
        int sum=0;
        sort(v.begin() , v.end());
        for(int i=0 ; i<v.size() ; i++){
            if(st.empty()) st.push(v[i]);
            else{
                if(st.top() < v[i]) st.push(v[i]);
                else if(st.top() == v[i]){
                    st.push(v[i]+1);
                    sum+=1;
                }
                else{
                    int add = abs(st.top() - v[i]);
                    st.push(v[i]+1+add);
                    sum+=(add+1);
                }
            }
        }
        return sum;
    }
};