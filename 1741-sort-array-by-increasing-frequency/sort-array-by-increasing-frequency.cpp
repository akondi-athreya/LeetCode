class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<vector<int>>v1;
        int n=nums.size();
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for (auto it : mp) {
            v1.push_back({it.first, it.second});
        }

        sort(begin(v1), end(v1), [](const vector<int>& a, const vector<int>& b) {
            return (a[1] < b[1]) || (a[1] == b[1] && a[0] > b[0]);
        });
        vector<int>ans;
        for(int i=0;i<v1.size();i++){
            for(int j=0;j<v1[i][1];j++){
                ans.push_back(v1[i][0]);
            }
        }
        return ans;

    }
};