class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        set<char> s = {'a', 'e', 'i', 'o', 'u'};
        int n = words.size();
        vector<int> v(n);
        for(int i=0 ; i<n ; i++) {
            string str = words[i];
            if(s.count(str.front()) and s.count(str.back())) {
                v[i] = 1;
            }
            else v[i] = 0;
        }
        vector<int> pre(n);
        pre[0] = v[0];
        for(int i=1 ; i<n ; i++) {
            pre[i] = v[i]+pre[i-1];
        }
        v.clear();
        for(auto i : queries) {
            int l = i[0];
            int r = i[1];
            if(l == 0) v.emplace_back(pre[r]);
            else {
                v.emplace_back(pre[r] - pre[l-1]);
            }
        }
        return v;
    }
};