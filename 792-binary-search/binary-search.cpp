class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==1 && nums[0]==target) return 0;
        int l=0 , h=n-1;
        while(l<=h){
            int m = (l+h)/2;
            if(nums[m] == target) return m;
            else if(nums[m] > target) h=m-1;
            else if(nums[m] < target) l=m+1;
        }
        return -1;
    }
};