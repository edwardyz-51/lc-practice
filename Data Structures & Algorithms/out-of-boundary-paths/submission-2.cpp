
class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        const int MOD = 1e9 + 7;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[startRow][startColumn] = 1;

        int ans = 0;
        int dir[] = {0, 1, 0, -1, 0};

        for (int move = 1; move <= maxMove; ++move) {
            vector<vector<int>> next(m, vector<int>(n, 0));

            for (int r = 0; r < m; ++r) {
                for (int c = 0; c < n; ++c) {
                    for (int d = 0; d < 4; ++d) {
                        int nr = r + dir[d];
                        int nc = c + dir[d + 1];

                        if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                            ans = (ans + dp[r][c]) % MOD;
                        } else {
                            next[nr][nc] = (next[nr][nc] + dp[r][c]) % MOD;
                        }
                    }
                }
            }

            dp = next;
        }

        return ans;
    }
};
