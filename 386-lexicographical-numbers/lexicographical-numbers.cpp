class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> v;
        int num = 1;
        for (int i=0 ; i<n ; i++) {
            v.emplace_back(num);
            if (num * 10 <= n) {
                num *= 10;
            } else {
                while (num%10 == 9 || num >= n) {
                    num /= 10;
                }
                num += 1;
            }
        }
        return v;
    }
};