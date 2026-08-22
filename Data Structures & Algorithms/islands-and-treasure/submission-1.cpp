class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int,int>> bfsQueue;

        // Add all treasure locations (value = 0) to the queue
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 0) {
                    bfsQueue.push({r, c});
                }
            }
        }

        // Directions: down, up, right, left
        vector<pair<int,int>> directions = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };

        // Perform BFS
        while (!bfsQueue.empty()) {
            int curRow = bfsQueue.front().first;
            int curCol = bfsQueue.front().second;
            bfsQueue.pop();

            for (auto& dir : directions) {
                int nextRow = curRow + dir.first;
                int nextCol = curCol + dir.second;

                // Skip out-of-bounds or walls
                if (nextRow < 0 || nextRow >= rows ||
                    nextCol < 0 || nextCol >= cols ||
                    grid[nextRow][nextCol] == -1) {
                    continue;
                }

                // If this path gives a shorter distance, update it
                int newDist = grid[curRow][curCol] + 1;
                if (grid[nextRow][nextCol] > newDist) {
                    grid[nextRow][nextCol] = newDist;
                    bfsQueue.push({nextRow, nextCol});
                }
            }
        }
    }
};
