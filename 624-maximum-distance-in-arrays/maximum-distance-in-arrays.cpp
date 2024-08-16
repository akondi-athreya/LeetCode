class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mi = arrays[0].front();
        int ma = arrays[0].back();
        int res = 0;
        for(int i=1 ; i<arrays.size() ; i++){
            int cmi = arrays[i].front();
            int cma = arrays[i].back();
            res = max({res , abs(cmi-ma) , abs(cma-mi)});
            ma = max(ma , cma);
            mi = min(mi , cmi);
        }
        return res;
    }
};