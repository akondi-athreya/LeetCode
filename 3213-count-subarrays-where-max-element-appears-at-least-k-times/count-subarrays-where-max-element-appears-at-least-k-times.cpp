class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        map<int,int> mp;
        int i=0 , j=0 , n = nums.size();
        int mx = *max_element(nums.begin() , nums.end());
        long long ans = 0;
        while(j<n){
            mp[nums[j]]++;
            while(mp[mx]>=k){
                ans = ans+n-j;
                mp[nums[i]]--;
                i++;
            }
            j++;
        }
        return ans;
    }
};