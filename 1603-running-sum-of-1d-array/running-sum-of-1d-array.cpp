class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> pre;
        pre.push_back(nums[0]);
        for(int i=1 ; i<nums.size() ; i++){
            int data = nums[i]+pre[i-1];
            pre.push_back(data);
        }
        return pre;
    }
};