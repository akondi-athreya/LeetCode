class Solution {
public:
    void solve(vector<int> &nums , int start , vector<vector<int>> &result){
        if(start==nums.size()-1){
            result.emplace_back(nums);
            return;
        }
        unordered_set<int> usedValues;
        for(int i=start ; i<nums.size() ; i++){
            if (usedValues.count(nums[i]) > 0) continue;
            swap(nums[start] , nums[i]);
            solve(nums,start+1,result);
            swap(nums[start] , nums[i]);
            usedValues.insert(nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums,0,ans);
        return ans;
    }
};