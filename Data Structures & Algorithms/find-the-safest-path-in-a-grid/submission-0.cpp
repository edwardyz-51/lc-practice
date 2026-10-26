class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        size_t N = grid.size(), M = grid.front().size();
        queue<pair<int,int>>srcBfs;
        for (size_t row(0uz); row < N; ++row)
            for (size_t col(0uz); col < M; ++col)
                if (grid[row][col])
                    srcBfs.emplace(row,col);
                
        constexpr int dir[] = {0,1,0,-1,0};
        while (!srcBfs.empty()){
            size_t sz = srcBfs.size();
            for (size_t _(0uz); _ < sz; ++_){
                auto [r,c] = srcBfs.front();
                int safety = grid[r][c];
                srcBfs.pop();
                for (size_t i(0uz); i < 4; ++i){
                    int nr = r+dir[i], nc = c+dir[i+1];
                    if (nr < 0 || nr == N || nc < 0 || nc == M 
                    || grid[nr][nc]!=0) continue;
                    grid[nr][nc]=safety+1;
                    srcBfs.emplace(nr,nc);
                }
            }
        }
        
        
        priority_queue<tuple<int,int,int>> pq;
        vector<vector<int>> best(N, vector<int>(M, -1));

        pq.emplace(grid[0][0], 0, 0);
        best[0][0] = grid[0][0];

        while (!pq.empty()) {
            auto [safety, r, c] = pq.top();
            pq.pop();

            if (r == N-1 && c == M-1)
                return safety - 1;

            if (safety < best[r][c]) continue;

            for (int i = 0; i < 4; ++i) {
                int nr = r + dir[i], nc = c + dir[i+1];

                if (nr < 0 || nr >= N || nc < 0 || nc >= M)
                    continue;

                int ns = min(safety, grid[nr][nc]);

                if (ns > best[nr][nc]) {
                    best[nr][nc] = ns;
                    pq.emplace(ns, nr, nc);
                }
            }
        }

        return 0;
            
            
            
    }
};
