class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int,int> mp;
        vector<int> res;
        int sum=0;
        int n = nums.size();
        for(int i=0 ; i<n ; i++){
            mp[nums[i]]++;
            sum+=nums[i];
        }
        for(auto it:mp){
            if(it.second==2){
                res.emplace_back(it.first);
                break;
            }
        }
        int mis = n*(n+1)/2;
        res.emplace_back((mis+res[0]-sum));
        return  res;

    }
};