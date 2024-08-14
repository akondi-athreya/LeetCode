class Solution {
public:
    int fun(vector<int>&v , int m){
        int i=0;
        int j=1;
        int n = v.size();
        int pcnt = 0;
        while(j<n){
            while(v[j]-v[i]>m) i++;
            pcnt+=(j-i);
            j++;
        }
        return pcnt;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin() , nums.end());
        int l=0;
        int r=nums[n-1]-nums[0];
        int ans=0;
        while(l<=r){
            int m = l+(r-l)/2;
            int cnt = fun(nums,m);
            if(cnt < k) l = m+1;
            else {
                ans = m;
                r = m-1;
            }
        }
        return ans;
    }
};