class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> memo(n, vector<int>(m, -1));
        auto dfs = [&](auto& self, int i, int j) -> int {
            if (i == n) return m - j; // Insert remaining characters.
            if (j == m) return n - i; // Delete remaining characters.

            if (memo[i][j] != -1)
                return memo[i][j];

            if (word1[i] == word2[j])
                return memo[i][j] = self(self,i + 1, j + 1);

            int remove = self(self,i + 1, j);
            int insert = self(self,i, j + 1);
            int replace = self(self,i + 1, j + 1);

            return memo[i][j] = 1 + min({remove, insert, replace});
        };

        return dfs(dfs,0, 0);
    }
};