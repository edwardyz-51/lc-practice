class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        directions = [[1,0],[0,1],[-1,0],[0,-1]]
        islands=0
        def dfs(r, c):
            if r<0 or c<0 or r>=len(grid) or c>=len(grid[0]) or grid[r][c]=="0":
                return
            grid[r][c]="0"
            for dx,dy in directions:
                dfs(r+dx,c+dy)
        for row in range(len(grid)):
            for col in range(len(grid[0])):
                if grid[row][col] == "1":
                    islands+=1
                    dfs(row,col)
        return islands
