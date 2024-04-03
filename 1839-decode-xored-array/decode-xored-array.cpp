class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> res;
        res.emplace_back(first);
        for(int i=1 ; i<=encoded.size() ; i++){
            res.emplace_back(res[i-1]^encoded[i-1]);
        }
        return res;
    }
};