class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum=0;
        int ans=0;
        int n = nums.size();
        unordered_map<int,int> mp;
        mp[0]++;
        
        for(int i=0 ; i<n ; i++){
            sum+=nums[i];
            int res = sum%k;
            if(res<0){
                res+=k;
            }
            ans+=mp[res];
            mp[res]++;
        }
        return ans;
    }
};