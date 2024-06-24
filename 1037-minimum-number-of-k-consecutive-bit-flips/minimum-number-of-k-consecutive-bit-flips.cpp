class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size() , ans=0 , t=0;
        for(int i=0 ; i<n ; i++){
            if(i>=k){
                if(nums[i-k] >1){
                    nums[i-k] -= 2;
                    t -= 1;
                }
            }
            if((nums[i]==1 && t%2==1) || (nums[i]==0 && t%2==0)){
                if(i+k > n) return -1;
                ans++;
                t++;
                nums[i]+=2;
            }
        }
        return ans;
    }
};