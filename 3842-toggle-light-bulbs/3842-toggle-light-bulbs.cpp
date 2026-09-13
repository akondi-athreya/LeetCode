class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<bool> v(100, false);
        for (int num : bulbs) {
            v[num-1] = !v[num-1];
        }
        vector<int> ans;
        for (int i = 0 ; i < 100 ; i++) {
            if (v[i]) ans.push_back(i+1);
        }
        return ans;
    }
};