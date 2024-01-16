class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        int j=nums.size()-1;
        vector<int> res;
        int sum=0;
        while(i<j){
            sum=nums[i]+nums[j];
            res.push_back(sum);
            i+=1;
            j-=1;
            sum=0;
        }
        return *max_element(res.begin(),res.end());
    }
};