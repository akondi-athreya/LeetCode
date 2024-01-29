class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int sum=0,max=0;
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i]==1){
                sum+=1;
            }
            else{
                if(max<sum){
                    max=sum;
                }
                sum=0;
            }
        }
        if(sum>max) return sum;
        return max;
    }
};