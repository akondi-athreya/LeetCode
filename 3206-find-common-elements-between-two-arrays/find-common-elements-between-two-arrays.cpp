class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mp1(101, 0);
        vector<int> mp2(101, 0);
        for (int i : nums1) mp1[i]++;
        for (int i : nums2) mp2[i]++;
        int a = 0 , b = 0;
        for (int i : nums1) {
            if (mp2[i] != 0) a++;
        }
        for (int i : nums2) {
            if (mp1[i] != 0) b++;
        }
        return {a, b};
    }
};