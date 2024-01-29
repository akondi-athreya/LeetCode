class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        /* int sum=0,max=0;
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
        return max; */

        vector<int> pre;
        pre.emplace_back(nums[0]);
        for(int i=1 ; i<nums.size() ; i++){
            int data = pre[i-1]+nums[i];
            if(nums[i]==0) data = 0;
            pre.emplace_back(data);
        }
        return *max_element(pre.begin(),pre.end());
    }
};