class Solution {
    int distance(const vector<int>& a, const vector<int>& b) { 
        // FIX 1: Correct the Manhattan distance formula between points a and b
        return abs(a[0] - b[0]) + abs(a[1] - b[1]); 
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        // Adjacency list: node -> list of {distance, neighbor_node}
        unordered_map<int, vector<vector<int>>> adj; 
        
        for (int i = 0; i < n; ++i) {
            int x = points[i][0], y = points[i][1];
            for (int j = i + 1; j < n; ++j) {
                int dist = distance({x, y}, points[j]);
                adj[i].push_back({dist, j});
                adj[j].push_back({dist, i});
            }
        }
        
        vector<bool> seen(n, false);
        // FIX 2: Do not set seen[0] = true here. Let the while loop handle it when popped.
        
        // FIX 3: Change greater<int> to greater<vector<int>> to match the queue elements
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> PRIMS; 
        
        PRIMS.push({0, 0}); // {cost, node}
        int ans = 0;
        
        while (!PRIMS.empty()) {
            int cost = PRIMS.top()[0];
            int node = PRIMS.top()[1];
            PRIMS.pop();
            
            if (seen[node]) continue;
            seen[node] = true;
            ans += cost;
            
            for (const vector<int>& nei : adj[node]) {
                if (!seen[nei[1]]) {
                    // FIX 4: Push 'nei' directly instead of wrapping it in braces '{nei}'
                    PRIMS.push(nei); 
                }
            }
        }
        return ans;
    }
};