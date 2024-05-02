class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        for(int i=nums.size()-1 ; i>=0 ; i--){
            int n = -1*nums[i];
            if(binary_search(nums.begin() , nums.end() , n)){
                return nums[i];
            }
        }
        return -1;
    }
};