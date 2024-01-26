class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        vector<int> l;

        while (i <= j) {
            int a = height[i];
            int b = height[j];
            int hei = std::min(a, b);
            int wid = j - i;
            int area = hei * wid;
            l.push_back(area);
            
            if (a <= b) {
                i++;
            } else {
                j--;
            }
        }

        return *max_element(l.begin(), l.end());
    }
};