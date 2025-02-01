class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        for(int i=1 ; i<n ; i++) {
            int one = nums[i-1];
            int two = nums[i];
            if(one%2 == 0 && one != 1) {
                if(two%2 != 0 || two == 1) {
                    continue;
                }
                else {
                    return false;
                }
            }
            else if(one%2 != 0 || one == 1) {
                if(two%2 == 0 && two != 1) {
                    continue;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};