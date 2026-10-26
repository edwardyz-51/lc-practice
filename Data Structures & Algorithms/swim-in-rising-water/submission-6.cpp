class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>best(n,vector<int>(n,INT_MAX));
        priority_queue<array<int, 3>,vector<array<int, 3>>,greater<array<int, 3>>>pq;
        constexpr int dir[] = {0,1,0,-1,0};
        pq.push({grid[0][0],0,0});
        while (!pq.empty()){
            auto [peak,row,col] = pq.top();
            pq.pop();
            if (peak > best[row][col]) continue;
            for (size_t i(0uz); i < 4; ++i){
                int nr = row + dir[i], nc = col + dir[i+1];
                if (nr < 0 || nc < 0 || nr == n || nc == n) continue;
                int new_peak = max(peak, grid[nr][nc]);
                if (nr + 1 == n && nc + 1 == n) return new_peak;
                if (new_peak < best[nr][nc]) { 
                    best[nr][nc] = new_peak;
                    pq.push({new_peak,nr,nc});
                }
            }
        }
        return n==1 ? grid[0][0] : -1;
    }
};
