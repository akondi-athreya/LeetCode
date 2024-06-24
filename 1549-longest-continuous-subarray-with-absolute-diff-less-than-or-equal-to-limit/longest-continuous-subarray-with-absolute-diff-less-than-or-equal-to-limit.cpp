class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size() , i=0 , j=0 , mx = 0;
        priority_queue<pair<int,int>> maxh;
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> minh;
        while(j<n){
            maxh.push({nums[j] , j});
            minh.push({nums[j] , j});
            int d = maxh.top().first - minh.top().first;
            while(i<j && d>limit){
                i = min(maxh.top().second , minh.top().second) + 1;
                while(maxh.top().second < i) maxh.pop();
                while(minh.top().second < i) minh.pop();
                d = maxh.top().first - minh.top().first;
            }
            mx = max(mx , j-i+1);
            j++;
        }
        return mx;
    }
};