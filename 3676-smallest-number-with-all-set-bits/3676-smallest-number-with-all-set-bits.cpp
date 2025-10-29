class Solution {
public:
    int smallestNumber(int n) {
        // if ((n & (n + 1)) == 0) return n;
        // while (true) {
        //     n++;
        //     if ((n & (n + 1)) == 0) return n;
        // }

        unsigned int x = static_cast<unsigned int>(n);

        x |= x >> 1;
        x |= x >> 2;
        x |= x >> 4;
        x |= x >> 8;
        x |= x >> 16;

        return static_cast<int>(x);
    }
};