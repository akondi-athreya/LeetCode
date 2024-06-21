class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ws=0 , zs=0 , mx=0 , n=customers.size();
        for(int i=0 ; i<n ; i++){
            if(grumpy[i]==0) zs+=customers[i];
            if(i<minutes) ws += (grumpy[i]==1 ? customers[i]:0);
            else{
                ws += (grumpy[i] == 1 ? customers[i] : 0) - (grumpy[i-minutes] == 1 ? customers[i-minutes] : 0);
            }
            mx = max(mx , ws);
        }
        return mx+zs;
    }
};