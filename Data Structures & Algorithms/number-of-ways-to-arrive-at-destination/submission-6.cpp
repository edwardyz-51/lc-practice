class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        constexpr int MOD = 1e9+7;
        vector<long long>ways(n,0), best(n,LLONG_MAX);
        ways[0]=1;
        best[0]=0;
        vector<vector<pair<int,int>>>adj(n);
        for (vector<int>& road : roads){
            adj[road[0]].emplace_back(road[2],road[1]);
            adj[road[1]].emplace_back(road[2],road[0]);
        }

        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>>pq;
        pq.emplace(0,0);
        while(!pq.empty()){
            auto [time,node] = pq.top();
            pq.pop();
            if (time > best[node]) continue;
            if (node==n-1) return ways[node] % MOD;
            for (auto&[cost,newNode] : adj[node]){
                int newTime = time + cost;
                if (best[newNode] < newTime) continue;
                if (best[newNode]==newTime) ways[newNode] = (ways[newNode] + ways[node]) % MOD;
                else{
                    best[newNode]=newTime;
                    ways[newNode]=ways[node];
                    pq.emplace(newTime,newNode);
                } 
            }
        }
        return -1;


    }
};
