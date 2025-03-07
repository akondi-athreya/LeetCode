class Solution {
public:
    vector<bool> Primes;

    void SieveOfEratosthenes(int n) {
        Primes.assign(n + 1, true);
        Primes[0] = Primes[1] = false;
        for (int p = 2; p * p <= n; p++) {
            if (Primes[p]) {
                for (int i = p * p; i <= n; i += p)
                    Primes[i] = false;
            }
        }
    }

    vector<int> closestPrimes(int left, int right) {
        SieveOfEratosthenes(right);
        vector<int> ans;
        for (int i = left; i <= right; i++) {
            if (Primes[i]) ans.push_back(i);
        }

        if (ans.size() <= 1) return { -1, -1 };

        int minDiff = INT_MAX;
        vector<int> res(2);
        for (int i = 1; i < ans.size(); i++) {
            int diff = ans[i] - ans[i - 1];
            if (diff < minDiff) {
                minDiff = diff;
                res[0] = ans[i - 1];
                res[1] = ans[i];
            }
        }

        return res;
    }
};