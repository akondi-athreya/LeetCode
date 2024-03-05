class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> v = nums;
        sort(v.begin() , v.end());
        for(int i=0 ; i<v.size() ; i++){
            int t = nums[0];
            nums.erase(nums.begin());
            nums.emplace_back(t);
            if(nums == v) return true;
        }
        return false;
    }
};