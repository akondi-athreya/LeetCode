class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size(), m = s.size();
        int i = n-1, j = m-1;
        sort(begin(g), end(g));
        sort(begin(s), end(s));

        int cnt = 0;

        while (i >= 0 && j >= 0) {
            if (g[i] <= s[j]) {
                cnt++;
                // cout << "i : " << i << " , j : " << j << "\n";
                i--;
                j--;
            }
            else {
                i--;
            }
        }

        return cnt;
    }
};

// |
// 2 3 - i
// 1 2 - j