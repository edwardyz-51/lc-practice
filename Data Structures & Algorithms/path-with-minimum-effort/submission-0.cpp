class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int ans = 0;
        int n = heights.size(), m = heights.front().size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>minHeap;
        minHeap.push({0,0,0});
        vector<pair<int,int>>directions = {
            {1,0},
            {0,1},
            {-1,0},
            {0,-1}
        };
        vector<vector<int>>distance(n,vector<int>(m,INT_MAX));
        distance[0][0]=0;
        while (!minHeap.empty()){
            int effort = minHeap.top()[0], row = minHeap.top()[1], col = minHeap.top()[2];
            minHeap.pop();
            if (row == n - 1 && col == m - 1) return effort;
            for (auto& [dx,dy] : directions){
                int dr = row + dx, dc = col + dy;
                if (dr  < 0 || dc < 0 || dr == n || dc ==m) continue;
                int new_effort = max(effort, abs(heights[dr][dc] - heights[row][col]));
                if (new_effort < distance[dr][dc]){
                    distance[dr][dc]=new_effort;
                    minHeap.push({new_effort,dr,dc});
                }

            }

        }
        return 0;

    }
};