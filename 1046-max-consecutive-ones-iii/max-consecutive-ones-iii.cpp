class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int mx=0;
        int j=0;
        for(int i=0;i<nums.size();i++){

            if (nums[i]==0)k--;
            
            while(k<0){
                if (nums[j]==0)k++;
                j++;
            }
            //cout<<j;
            mx=max(mx,i-j+1);
        
        }
        return mx;
    }
};