class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> sum;
        sum.push_back(nums[0]);
        for(int i=1 ; i<nums.size() ; i++){
            int data = nums[i]+sum[i-1];
            sum.push_back(data);
        }
        
        int lsum=0,rsum=0;
        int tsum=sum[nums.size()-1];
        for(int i=0 ; i<nums.size() ; i++){
            if(i==0){
                lsum=0;
            }
            else{
                lsum = sum[i-1];
            }
            rsum = tsum-sum[i];
            if(lsum==rsum){
                return i;
            }
        }
        return -1;
    }
};