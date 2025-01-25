class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        multimap<int, pair<int, int>> mp;
        for(int i=0 ; i<k ; i++) {
            mp.insert({nums[i][0], {i, 0}});
        }
        vector<int> ansvec(2);
        int ans = INT_MAX;
        while (true) {
            int fi = mp.begin()->first;
            int la = mp.rbegin()->first;
            if (la-fi < ans) {
                ans = la-fi;
                ansvec[0] = fi;
                ansvec[1] = la;
            }
            int fi_ind = mp.begin()->second.first;
            int la_ind = mp.begin()->second.second;
            mp.erase(mp.begin());
            if (la_ind+1 == nums[fi_ind].size()) {
                break;
            }
            else mp.insert({nums[fi_ind][la_ind+1], {fi_ind, la_ind+1}});
        }
        return ansvec;
    }
};