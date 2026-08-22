class Solution {
public:
    void dfs(int row, int col, int& area, vector<vector<int>>& grid) {
        area++;
        grid[row][col] = 0;

        if (col - 1 >= 0 && grid[row][col - 1] == 1) {
            dfs(row, col - 1, area, grid);
        }

        if (col + 1 < grid[0].size() && grid[row][col + 1] == 1) {
            dfs(row, col + 1, area, grid);
        }

        if (row - 1 >= 0 && grid[row - 1][col] == 1) {
            dfs(row - 1, col, area, grid);
        }

        if (row + 1 < grid.size() && grid[row + 1][col] == 1) {
            dfs(row + 1, col, area, grid);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;

        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                if (grid[row][col] == 1) {
                    int area = 0;
                    dfs(row, col, area, grid);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};