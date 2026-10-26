class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        size_t n = grid.size(), m = grid[0].size();

        vector<int> rows(n);
        vector<int> cols(m);

        for (size_t r = 0; r < n; ++r) {
            for (size_t c = 0; c < m; ++c) {
                if (grid[r][c]) {
                    rows[r]++;
                    cols[c]++;
                }
            }
        }

        int servers = 0;

        for (size_t r = 0; r < n; ++r) {
            for (size_t c = 0; c < m; ++c) {
                if (grid[r][c] && (rows[r] > 1 || cols[c] > 1)) {
                    servers++;
                }
            }
        }

        return servers;
    }
};