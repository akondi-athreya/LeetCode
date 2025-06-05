class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ele1, ele2, cnt1=0, cnt2=0;
        vector<int> ans;
        for(int i = 0 ; i < n ; i++) {
            if(cnt1 == 0 && nums[i] != ele2) {
                ele1 = nums[i];
                cnt1 = 1;
            }
            else if(cnt2 == 0 && nums[i] != ele1) {
                ele2 = nums[i];
                cnt2 = 1;
            }
            else if(nums[i] == ele1) cnt1++;
            else if(nums[i] == ele2) cnt2++;
            else cnt1--,cnt2--;
        }
        cnt1 = 0, cnt2 = 0;
        for(int i = 0 ; i < n ; i++) {
            if(nums[i] == ele1) cnt1++;
            else if(nums[i] == ele2) cnt2++;
        }
        int mini = (int)(n/3) + 1;
        if(cnt1 >= mini) ans.emplace_back(ele1);
        if(cnt2 >= mini) ans.emplace_back(ele2);
        if(ans.size() == 2 && ans[0] > ans[1]) swap(ans[0], ans[1]);
        return ans;
    }
};