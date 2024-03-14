class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> mp;
        int sum=0 , cnt=0;
        for(int i=0 ; i<nums.size() ; i++){
            sum += nums[i];
            if(sum==goal) cnt++;
            if(mp.find(sum-goal) != mp.end()) cnt+=mp[sum-goal];
            if(mp.find(sum) != mp.end()) mp[sum]++;
            else mp[sum]=1;
        }
        return cnt;
    }
};