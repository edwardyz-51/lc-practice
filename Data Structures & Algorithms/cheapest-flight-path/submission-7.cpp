class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int,int>>bfs; // {node,price}
        vector<vector<pair<int,int>>> adj(n); //adj[i] = {{dest,price}, ...}
        for (const vector<int>& flight : flights){
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        int taken = -1;
        int ans = INT_MAX;
        vector<int> distance(n,INT_MAX);
        bfs.push({src,0});
        while (!bfs.empty() && taken <= k){
            int sz = bfs.size();
            for (int i = 0; i < sz; ++i){
                auto [node,price] = bfs.front();
                bfs.pop();
                if (node==dst) {
                    ans=min(ans,price);
                    distance[dst] = max(distance[dst],price);
                    continue;
                }
                if (distance[node] < price) continue;
                distance[node]=price;
                for (auto& [dest, cost] : adj[node]){
                    int np = price + cost;
                    if (np < distance[dest]) bfs.push({dest,np});
                }
                
            }
            taken++;
        }
        return ans==INT_MAX ? -1 : ans;

    }
};
