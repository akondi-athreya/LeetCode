class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        int l=0 , h=n-1;
        int mid = (l+h)/2;
        while(l <= h) {
            mid = (l + h) / 2;
            if(nums[mid] == target) break;
            else if(nums[mid] > target) h = mid - 1;
            else l = mid + 1;
        }
        int f = mid, s = mid;
        if(nums[mid] != target) return {};
        while(f>0) {
            if(nums[f-1] == target) f--;
            else break;
        }
        while(s<n-1) {
            if(nums[s+1] == target) s++;
            else break;
        }
        if(f == s) return {f};
        else {
            vector<int> v;
            for(int i=f ; i<=s ; i++){
                v.emplace_back(i);
            }
            return v;
        }
    }
};