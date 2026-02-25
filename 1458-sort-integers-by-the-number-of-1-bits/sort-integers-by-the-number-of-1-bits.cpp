class Solution {
public:
    int fun(int n) {
        int cnt = 0;
        while (n > 0) {
            if (n & 1)
                cnt++;

            n = n >> 1;
        }
        return cnt;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int, int>> temp;

        for (int num : arr) {
            temp.push_back({fun(num), num});
        }

        sort(temp.begin(), temp.end());

        for (int i = 0; i < arr.size(); i++) {
            arr[i] = temp[i].second;
        }

        return arr;
    }
};