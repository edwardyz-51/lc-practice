class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime(right + 1, true);

        for (int p = 2; p * p <= right; ++p) {
            if (!isPrime[p]) continue;

            for (int j = p * p; j <= right; j += p) {
                isPrime[j] = false;
            }
        }

        vector<int> ans = {-1, -1};
        int previous = -1;
        int bestGap = INT_MAX;

        for (int i = max(left, 2); i <= right; ++i) {
            if (!isPrime[i]) continue;

            if (previous != -1 && i - previous < bestGap) {
                bestGap = i - previous;
                ans = {previous, i};
            }

            previous = i;
        }

        return ans;
    }
};