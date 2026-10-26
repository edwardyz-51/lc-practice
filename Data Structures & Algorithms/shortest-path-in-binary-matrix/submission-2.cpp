class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        size_t n = grid.size();
        if (grid[0][0] || grid[n-1][n-1]) return -1;
        if (n==1) return 1;
        vector<pair<int,int>>dir = {
            {0,-1},
            {-1,-1},
            {1,0},
            {1,1},
            {0,1},
            {-1,1},
            {-1,0},
            {-1,-1}
        };
        int steps = 1;
        
        queue<pair<int,int>>bfs;
        vector<vector<bool>>seen(n,vector<bool>(n,false));
        seen[0][0]=true;
        bfs.push({0,0});
        while (!bfs.empty()){
            size_t sz = bfs.size();
            for (size_t _(0uz); _ < sz; ++_){
                auto [row,col] = bfs.front();
                bfs.pop();
                for (const auto& [dr,dc] : dir){
                    int nr = row + dr, nc = col + dc;
                    if (nr==n-1 && nc==n-1) return steps+1;
                    if (nr < 0 || nc < 0 || nr == n 
                    || nc == n || seen[nr][nc] || grid[nr][nc]!=0) continue;
                    seen[nr][nc]=true;
                    bfs.push({nr,nc});
                }
            }
            steps++;
        }
        return -1;
    }
};