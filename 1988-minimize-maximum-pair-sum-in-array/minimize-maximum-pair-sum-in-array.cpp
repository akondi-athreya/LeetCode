class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        int j=nums.size()-1;
        int sum=0;
        int max=0;
        while(i<j){
            sum=nums[i]+nums[j];
            if(sum>max){
                max=sum;
            }
            i+=1;
            j-=1;
            sum=0;
        }
        return max;
    }
};