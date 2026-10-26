class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<double,int>>>adj(n);
        for (size_t i(0uz); i < edges.size(); ++i){
            adj[edges[i][0]].push_back({succProb[i],edges[i][1]});
            adj[edges[i][1]].push_back({succProb[i],edges[i][0]});
        }
        vector<double>prob(n,0);
        priority_queue<pair<double,int>>pq;
        pq.push({1.0,start_node});
        prob[start_node] = 1.0;
        while (!pq.empty()){
            auto [probability, prev] = pq.top();
            if (prev == end_node) return probability;
            pq.pop();
            for (const auto& [cost, node] : adj[prev]){
                double new_prob = probability * cost;
                if (new_prob <= prob[node]) continue;
                prob[node] = new_prob;
                pq.push({new_prob,node});
            }
        }
        return prob[end_node];

    }
};