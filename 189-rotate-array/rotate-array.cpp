class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        /* while(k--){
            int n = nums.size()-1;
            int dig = nums[n];
            nums.pop_back();
            nums.insert(nums.begin(),dig);
        } */

        k=k%nums.size();
        reverse(nums.begin(),nums.begin()+(nums.size()-k));
        reverse(nums.begin()+(nums.size()-k),nums.end());
        reverse(nums.begin(),nums.end());
    }
};