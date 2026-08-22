class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        directions = [[1,0], [-1,0], [0,-1], [0,1]]
        n = len(grid)
        m = len(grid[0])

        def dfs(r, c):
            if r < 0 or c < 0 or r == n or c == m or grid[r][c] == 0:
                return 0

            grid[r][c] = 0
            area = 1

            for dr, dc in directions:
                area += dfs(r + dr, c + dc)

            return area

        max_area = 0

        for r in range(n):
            for c in range(m):
                if grid[r][c] == 1:
                    max_area = max(max_area, dfs(r, c))

        return max_area