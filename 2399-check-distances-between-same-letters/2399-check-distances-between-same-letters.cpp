class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        map<char, vector<int>> mp;
        for (int i = 0 ; i < s.size() ; i++) {
            mp[s[i]].push_back(i);
        }
        for (auto it : mp) {
            int x = it.second[0];
            int y = it.second[1];
            if (y-x-1 != distance[it.first - 'a']) return false;
        }
        return true;
    }
};