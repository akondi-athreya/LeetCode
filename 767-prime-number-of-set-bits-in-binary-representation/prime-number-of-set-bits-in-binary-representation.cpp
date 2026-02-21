class Solution {
public:
    set<int> st = {2, 3, 5, 7, 11, 13, 17, 19};
    int fun(int n) {
        int a = n;
        int set_bit_count = 0;
        while (a > 0) {
            if (a & 1) set_bit_count++;
            a = a >> 1;
        }
        if (st.count(set_bit_count)) return true;

        return false;
    }
    int countPrimeSetBits(int left, int right) {
        int cnt = 0;
        for (int i = left ; i <= right ; i++) {
            if (fun(i)) cnt++;
        }
        return cnt;
    }
};