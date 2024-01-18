class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        /* int first = -1, last = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                if (first == -1) {
                    first = i;
                }
                last = i;
            }
        }
        return {first, last}; */

        int low = 0, high = nums.size() - 1;
        int first = -1, last = -1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                first = mid;
                last = mid;
                while (first > 0 && nums[first - 1] == target) {
                    first--;
                }
                while (last < nums.size() - 1 && nums[last + 1] == target) {
                    last++;
                }
                break;
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return {first, last};
    }
};