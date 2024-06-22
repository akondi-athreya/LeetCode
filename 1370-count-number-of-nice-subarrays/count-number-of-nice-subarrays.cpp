class Solution {
public:
    int fun(vector<int>& v, int goal){
        int i=0 , j=0 , n=v.size() , cnt=0 , ans=0;
        while(j<n){
            if(v[j]%2) cnt++;
            while(i<=j && cnt>goal){
                if(v[i]%2) cnt--;
                i++;
            } 
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return fun(nums,k) - fun(nums,k-1);
    }
};