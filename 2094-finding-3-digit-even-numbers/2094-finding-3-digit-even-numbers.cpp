class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> v;
        vector<int> mp(10, 0);
        for (int &num : digits) {
            mp[num]++;
        }
        for (int i = 1 ; i <= 9 ; i++) {
            if (mp[i] == 0) continue;
            mp[i]--;
            for (int j = 0 ; j <= 9 ; j++) {
                if (mp[j] == 0) continue;
                mp[j]--;
                for (int k = 0 ; k <= 8 ; k+=2) {
                    if (mp[k] == 0) continue;
                    mp[k]--;
                    int ans = i*100 + j*10 + k;
                    v.push_back(ans);
                    mp[k]++;
                }
                mp[j]++;
            }
            mp[i]++;
        }
        return v;
    }
};