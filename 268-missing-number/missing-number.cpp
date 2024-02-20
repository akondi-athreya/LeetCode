class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int max = 0;
        int x = 0 , flag=0;
        if(nums.size()==1){
            if(nums[0]==0) return 1;
            else return 0;
        }
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i]==0) flag=1;
            if(nums[i] > max){
                max = nums[i];
            }
            x +=nums[i];
        }
        int sum = max*(max+1)/2;
        if(sum-x==0){
            if(flag==0) return 0;
            else return max+1;
        }
        else return sum-x;
    }
};