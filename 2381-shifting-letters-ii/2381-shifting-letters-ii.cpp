class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> v(n, 0);

        for (auto i : shifts) {
            if (i[2] == 1) {
                v[i[0]]++;
                if (i[1] + 1 < n) {
                    v[i[1] + 1]--;
                }
            } else {
                v[i[0]]--;
                if (i[1] + 1 < n) {
                    v[i[1] + 1]++;
                }
            }
        }

        string ans(n, ' ');
        int num = 0;

        for (int i = 0; i < s.size(); i++) {
            num = (num + v[i]) % 26;
            if (num < 0)
                num += 26;

            ans[i] = 'a' + (s[i] - 'a' + num) % 26;
        }

        return ans;
    }
};