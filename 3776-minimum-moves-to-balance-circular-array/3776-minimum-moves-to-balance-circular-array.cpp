class Solution {
public:
    long long minMoves(vector<int>& balance) {
        int n = balance.size();
        long long res = 0;
        int negpos = -1;
    
        for (int i = 0 ; i < n ; i++) {
            res += balance[i];
            if (balance[i] < 0) negpos = i;
        }
    
        if (res < 0) return -1;
        if (negpos == -1) return 0;
    
        long long need = -1LL * balance[negpos];
        long long moves = 0;
    
        vector<pair<int, long long>> v;
    
        for (int i = 0 ; i < n ; i++) {
            if (i == negpos || balance[i] <= 0) continue;
            int dist = abs(i - negpos);
            dist = min(dist, n - dist);
            v.push_back({dist, balance[i]});
        }
    
        sort(v.begin(), v.end());
    
        for (auto &[dist, amt] : v) {
            if (need == 0) break;
            long long take = min(amt, need);
            moves += take * dist;
            need -= take;
        }
    
        return (need == 0) ? moves : -1;
    }
};