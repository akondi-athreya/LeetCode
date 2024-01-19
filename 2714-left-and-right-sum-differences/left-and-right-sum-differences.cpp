class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> lsum,rsum,res;
        int data=0;
        lsum.emplace_back(0);
        for(int i=0 ; i<nums.size()-1 ; i++){
            data = lsum[i]+nums[i];
            lsum.emplace_back(data);
        }
        reverse(nums.begin(),nums.end());
        rsum.emplace_back(0);
        for(int i=0 ; i<nums.size()-1 ; i++){
            data = rsum[i]+nums[i];
            rsum.emplace_back(data);
        }
        reverse(rsum.begin(),rsum.end());
        for(int i=0 ; i<nums.size() ; i++){
            data = abs(lsum[i]-rsum[i]);
            res.emplace_back(data);
        }
        return res;
    }
};