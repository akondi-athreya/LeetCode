class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> pre;
        pre.emplace_back(0);
        for(int i=0 ; i<gain.size() ; i++){
            int sum = pre[i]+gain[i];
            pre.emplace_back(sum);
        }
        return *max_element(pre.begin(),pre.end());
    }
};