class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size();
        colors.insert(colors.end(), colors.begin(), colors.end());
        int cnt = 0;
        for (int i = 0 ; i < n ; i++) {
            if ((colors[i] == colors[i+2]) && (colors[i] != colors[i+1]))
                cnt++;
        }
        return cnt;
    }
};