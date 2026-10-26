class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        //just find the path with minimum max?
        int n = grid.size();
        if (n==1) return grid[0][0];
        vector<vector<int>>best(n,vector<int>(n,INT_MAX));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        vector<pair<int,int>> directions = {
            {1,0},
            {0,1},
            {-1,0},
            {0,-1}
        };
        pq.push({grid[0][0],0,0});
        while (!pq.empty()){
            int peak = pq.top()[0], row = pq.top()[1], col = pq.top()[2];
            pq.pop();
            for (const auto& [dr,dc] : directions){
                int nr = row + dr, nc = col + dc;
                if (nr < 0 || nc < 0 || nr == n || nc == n) continue;
                int new_peak = max(peak, grid[nr][nc]);
                if (nr + 1 == n && nc + 1 == n) return new_peak;
                if (new_peak < best[nr][nc]) { 
                    best[nr][nc] = new_peak;
                    pq.push({new_peak,nr,nc});
                }
            }
        }
        return -1;
    }
};
