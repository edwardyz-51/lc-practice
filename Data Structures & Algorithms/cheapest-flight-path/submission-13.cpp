//my original
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int,int>>bfs; // {node,price}
        vector<vector<pair<int,int>>> adj(n); //adj[i] = {{dest,price}, ...}
        for (const vector<int>& flight : flights)
            adj[flight[0]].emplace_back(flight[1], flight[2]);
        int taken = 0;
        vector<int> best(n,INT_MAX);
        //bad name. name something like best or cheapest
        bfs.push({src,0});
        while (!bfs.empty() && taken <= k){
            int sz = bfs.size();
            for (int i = 0; i < sz; ++i){
                auto [node,price] = bfs.front();
                bfs.pop();
                for (auto& [dest, cost] : adj[node]){
                    int np = price + cost;
                    if (np < best[dest]){
                        best[dest]=np;
                        bfs.push({dest,np});
                    } 
                }
                
            }
            taken++;
        }
        return best[dst] == INT_MAX ? -1 : best[dst];

    }
};
