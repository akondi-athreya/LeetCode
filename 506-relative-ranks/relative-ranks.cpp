class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int,int>> vec;
        int n = score.size();
        for(int i=0 ; i<n ; i++){
            vec.push_back({score[i],i});
        }
        sort(vec.rbegin() , vec.rend());
        vector<string> res(n);
        for(int i=0 ; i<n ; i++){
            if(i==0) res[vec[i].second] = "Gold Medal";
            else if(i==1) res[vec[i].second] = "Silver Medal";
            else if(i==2) res[vec[i].second] = "Bronze Medal";
            else res[vec[i].second] = to_string(i+1);
        }
        return res;
    }
};