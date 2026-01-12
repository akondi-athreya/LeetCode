class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1;
        int ans = INT_MIN;
        while (i <= j) {
            int a = height[i];
            int b = height[j];

            int wid = j-i;
            int area = min(a, b) * wid;

            ans = max(ans, area);

            if (a <= b) i++;
            else j--;
        }
        return ans;
    }
};