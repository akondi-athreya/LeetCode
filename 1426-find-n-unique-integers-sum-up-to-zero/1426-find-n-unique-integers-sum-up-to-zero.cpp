class Solution {
public:
    vector<int> sumZero(int n) {
        bool is_odd = (n&1) ? true : false;
        int x = n/2;
        vector<int> ans;
        for(int i = (-1 * x) ; i<=x ; i++) {
            if(i == 0 && !is_odd) continue;
            ans.emplace_back(i);
        }
        // if(!is_odd) {
        //     remove(begin(ans), end(ans), 0);
        // }
        return ans;
    }
};