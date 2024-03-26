class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<long long,long long> mp;
        for(long long i=0 ; i<nums.size() ; i++){
            mp[nums[i]]++;
        }
        long long mx = *max_element(nums.begin() , nums.end());
        for(long long i=1 ; i<=mx+1 ; i++){
            if(mp.find(i) == mp.end()){
                return i;
            }
        }
        return 1;
    }
};