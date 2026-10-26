class Solution {
public:
    int longestIdealString(string s, int k) {
        int dp[26] = {0}, ans = 0;

        for (char c : s) {
            int cur = c - 'a';
            for (int prev = max(0, cur - k); prev <= min(25, cur + k); ++prev) {
                dp[cur] = max(dp[cur], dp[prev]);
            }
            dp[cur]++;
            ans = max(ans, dp[cur]);
        }

        return ans;
    }
};