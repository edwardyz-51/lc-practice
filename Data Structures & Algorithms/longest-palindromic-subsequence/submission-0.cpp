class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // Base case: single character
        for (int i = 0; i < n; i++)
            dp[i][i + 1] = 1;

        for (int length = 2; length <= n; length++) {
            for (int start = 0; start + length <= n; start++) {
                int end = start + length;

                if (s[start] == s[end - 1]) {
                    dp[start][end] = 2 + dp[start + 1][end - 1];
                } else {
                    dp[start][end] = max(
                        dp[start + 1][end],
                        dp[start][end - 1]
                    );
                }
            }
        }

        return dp[0][n];
    }
};